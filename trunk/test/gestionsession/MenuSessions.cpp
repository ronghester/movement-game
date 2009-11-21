#include "MenuSessions.h"

MenuSessions::MenuSessions(QWidget *parent) : QWidget(parent) 
{
	// Création de la fenêtre.
	window = new QWidget;
	// Affichage en fullscreen directement.
	window->showFullScreen();
	
	// Ouverture du fichier contenant le nom des sessions.
	QFile session("sessions");
	QString nomSession;
	session.open(QIODevice::ReadOnly);
	
	// On recupere les dimensions de la fenetre en fullscreen.
	QRect dimensions = window->geometry();
   	this->largeurFenetre = dimensions.width();
    	this->hauteurFenetre = dimensions.height();
	
	//Creation des boutons.
	for (int i=0;i<4;i++)
	{
		nomSession = session.readLine();
		nomSession.resize(nomSession.size()-1);
		boutons[i] = new QPushButton(nomSession,this);
			boutons[i]->setFixedSize (this->largeurFenetre-25,(this->hauteurFenetre-100)/5);
			boutons[i]->setFont(QFont("", 40, QFont::Bold));
	}
	quit = new QPushButton("Quitter",this);
		quit->setFixedSize (this->largeurFenetre-25,(this->hauteurFenetre-100)/5);
		quit->setFont(QFont("", 40, QFont::Bold));
	session.close();

	// Création et remplissage du layout.
	layoutPrincipal = new QVBoxLayout(this);
	for (int i=0;i<4;i++)
		{ layoutPrincipal->addWidget(boutons[i]); }
    	layoutPrincipal->addWidget(quit);
    	window->setLayout(layoutPrincipal);
    	window->show();
    
    	// Attribution des signaux.
    	for (int i=0;i<4;i++)
		{ connect(boutons[i], SIGNAL(clicked()), this, SLOT(gestion_session())); }
    	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

}

// Slots
void MenuSessions::gestion_session()
{
	// On recupère l'emmetteur.
	QObject * emetteurA = sender();
	QPushButton * emetteur = qobject_cast<QPushButton*>(emetteurA);
	QString texte = emetteur->text();
	QString nouveau("Nouveau");
   
   	// On teste s'il s'agit d'un profil déjà créé ou non.
	if (texte == nouveau)
	{
		// Si c'est un nouvel utilisateur :
		// On demande un pseudo
		QString pseudo = QInputDialog::getText(this, "Pseudo","pseudo");
		//
		// TODO : Tester le retour du dialog. (!="Nouveau")
		//
		// On cherche à quelle place il se trouve, puis on créé un nouvel utilisateur.
		Utilisateur Bapt(pseudo);
		int place = 0;
		if (emetteur == this->boutons[0]) place=1;
		else if (emetteur == this ->boutons[1]) place=2;
		else if (emetteur == this ->boutons[2]) place=3;
		else if (emetteur == this ->boutons[3]) place=4;
		// On enregistre l'utilisateur et on met à jour le bouton correspondant.
		Bapt.enregistrer_utilisateur(place);
		boutons[place-1] = new QPushButton(pseudo,this);
		boutons[place-1]->setFixedSize (this->largeurFenetre-25,(this->hauteurFenetre-100)/5);
		boutons[place-1]->setFont(QFont("", 40, QFont::Bold));
		connect(boutons[place-1], SIGNAL(clicked()), this, SLOT(gestion_session()));
    		window->close();
    		// On créé la nouvelle fenêtre.
    		window = new QWidget;
    		// On créé et rempli le layout.
    		layoutPrincipal = new QVBoxLayout(this);
    		for (int i=0; i<4;i++)
    			{ layoutPrincipal -> addWidget(boutons[i]); }
    		layoutPrincipal->addWidget(quit);
    		window->setLayout(layoutPrincipal);
    		// On affiche la nouvelle fenêtre en plein écran
    		window->showFullScreen();	
		}
	else
	{
		// Si c'est un utilisateur enregistré :
		// On récupère son pseudo.
   		QObject * emetteurA = sender();
   		QPushButton * emetteur = qobject_cast<QPushButton*>(emetteurA);
   		QString texte = emetteur->text();
   	
   		// On créé un utilisateur avec le pseudo récupéré
   		Utilisateur joueur(texte);
   		// On lance son menu.
   		MenuUtilisateur menuJoueur(this,joueur);
   	
   		// Fermeture de la fenetre "MenuSessions"
   		window->close();
   		this->close(); 
	}
}
