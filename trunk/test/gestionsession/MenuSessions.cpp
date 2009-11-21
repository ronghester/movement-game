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
	    nomSession = session.readLine();	
	    nomSession.resize(nomSession.size()-1);			// On lit la Premiere ligne du fichier "sessions"
	    bouton1 = new QPushButton(nomSession,this);			// On créé le bouton avec le nom et le widget parent
	    	bouton1->setFixedSize (this->largeurFenetre-25,(this->hauteurFenetre-100)/5);
	    	bouton1->setFont(QFont("", 40, QFont::Bold));		// On définit la taille et la police du texte
	    nomSession = session.readLine();
	    nomSession.resize(nomSession.size()-1);			
	    bouton2 = new QPushButton(nomSession,this);
	    	bouton2->setFixedSize (this->largeurFenetre-25,(this->hauteurFenetre-100)/5);
	    	bouton2->setFont(QFont("", 40, QFont::Bold));
	    nomSession = session.readLine();
	    nomSession.resize(nomSession.size()-1);
	    bouton3 = new QPushButton(nomSession,this);
	    	bouton3->setFixedSize (this->largeurFenetre-25,(this->hauteurFenetre-100)/5);
	    	bouton3->setFont(QFont("", 40, QFont::Bold));
	    nomSession = session.readLine();
	    nomSession.resize(nomSession.size()-1);
	    bouton4 = new QPushButton(nomSession,this);
	    	bouton4->setFixedSize (this->largeurFenetre-25,(this->hauteurFenetre-100)/5);
	    	bouton4->setFont(QFont("", 40, QFont::Bold));
	    quit = new QPushButton("Quitter",this);
	    	quit->setFixedSize (this->largeurFenetre-25,(this->hauteurFenetre-100)/5);
	    	quit->setFont(QFont("", 40, QFont::Bold));
	    session.close();

	// Création et remplissage du layout.
    	layoutPrincipal = new QVBoxLayout(this);
    	layoutPrincipal->addWidget(bouton1);
    	layoutPrincipal->addWidget(bouton2);
    	layoutPrincipal->addWidget(bouton3);
    	layoutPrincipal->addWidget(bouton4);
    	layoutPrincipal->addWidget(quit);
    	window->setLayout(layoutPrincipal);
    	window->show();
    
    	// Attribution des signaux.
    	connect(bouton1, SIGNAL(clicked()), this, SLOT(gestion_session()));
    	connect(bouton2, SIGNAL(clicked()), this, SLOT(gestion_session()));
    	connect(bouton3, SIGNAL(clicked()), this, SLOT(gestion_session()));
    	connect(bouton4, SIGNAL(clicked()), this, SLOT(gestion_session()));
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
		// On créé un nouvel utilisateur et on teste sur quel bouton écrire.
		QString pseudo = QInputDialog::getText(this, "Pseudo","pseudo");
		//
		// TODO : Tester le retour du dialog. (!="Nouveau")
		//
		Utilisateur Bapt(pseudo);
		if (emetteur == this->bouton1)
		{ 
			// On enregistre l'utilisateur et on créé le nouveau bouton
			Bapt.enregistrer_utilisateur(1); 
   			bouton1 = new QPushButton(pseudo,this);
	    		bouton1->setFixedSize (this->largeurFenetre-25,(this->hauteurFenetre-100)/5);
	    		bouton1->setFont(QFont("", 40, QFont::Bold));
	    		connect(bouton1, SIGNAL(clicked()), this, SLOT(gestion_session()));
   		}
   		if (emetteur == this->bouton2)
   		{ 
   			Bapt.enregistrer_utilisateur(2);
   			bouton2 = new QPushButton(pseudo,this);
	    		bouton2->setFixedSize (this->largeurFenetre-25,(this->hauteurFenetre-100)/5);
	    		bouton2->setFont(QFont("", 40, QFont::Bold));
	    		connect(bouton2, SIGNAL(clicked()), this, SLOT(gestion_session()));
   		}
   		if (emetteur == this->bouton3)
   		{ 
   			Bapt.enregistrer_utilisateur(3); 
   			bouton3 = new QPushButton(pseudo,this);
	    		bouton3->setFixedSize (this->largeurFenetre-25,(this->hauteurFenetre-100)/5);
	    		bouton3->setFont(QFont("", 40, QFont::Bold));
	    		connect(bouton3, SIGNAL(clicked()), this, SLOT(gestion_session()));
   		}
   		if (emetteur == this->bouton4)
   		{
   			Bapt.enregistrer_utilisateur(4);
   	   		bouton4 = new QPushButton(pseudo,this);
   	   		bouton4->setFixedSize (this->largeurFenetre-25,(this->hauteurFenetre-100)/5);
	    		bouton4->setFont(QFont("", 40, QFont::Bold));
	    		connect(bouton4, SIGNAL(clicked()), this, SLOT(gestion_session()));
   		}
   		
    		window->close();
    		// On créé la nouvelle fenêtre.
    		window = new QWidget;
    		// On créé et rempli le layout.
    		layoutPrincipal = new QVBoxLayout(this);
    		layoutPrincipal->addWidget(bouton1);
    		layoutPrincipal->addWidget(bouton2);
    		layoutPrincipal->addWidget(bouton3);
    		layoutPrincipal->addWidget(bouton4);
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
