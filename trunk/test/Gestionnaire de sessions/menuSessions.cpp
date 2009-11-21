#include <QtGui>
#include <QLayout>
#include <QFile>
#include <QString>
#include <iostream>
#include "menuSessions.h"
#include "utilisateur.h"
#include "menuUtilisateur.h"

menuSessions::menuSessions(QWidget *parent) : QWidget(parent) 
{
	
	window = new QWidget;
	/* Affichage en fullscreen directement */
	window->showFullScreen();
	
	/* On ouvre le fichier contenant le nom des sessions */
	QFile session("sessions");
	QString nomSession;
	session.open(QIODevice::ReadOnly);
	
	/* On recupere les dimensions de la fenetre en fullscreen */
	QRect dimensions = window->geometry();
   	this->largeurFenetre = dimensions.width();
    	this->hauteurFenetre = dimensions.height();
	
	/* Creation des boutons */
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

	/* On ajoute les boutons à un layout principal */
    	layoutPrincipal = new QVBoxLayout(this);
    	layoutPrincipal->addWidget(bouton1);
    	layoutPrincipal->addWidget(bouton2);
    	layoutPrincipal->addWidget(bouton3);
    	layoutPrincipal->addWidget(bouton4);
    	layoutPrincipal->addWidget(quit);
    	window->setLayout(layoutPrincipal);
    	window->show();
    
    	/* Attribution des signaux */
    	connect(bouton1, SIGNAL(clicked()), this, SLOT(gestionSession()));
    	connect(bouton2, SIGNAL(clicked()), this, SLOT(gestionSession()));
    	connect(bouton3, SIGNAL(clicked()), this, SLOT(gestionSession()));
    	connect(bouton4, SIGNAL(clicked()), this, SLOT(gestionSession()));
    	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

}

/* Slots */
void menuSessions::gestionSession()
{
   QObject * emetteurA = sender();
   QPushButton * emetteur = qobject_cast<QPushButton*>(emetteurA);
   QString texte = emetteur->text();
   QString nouveau("Nouveau");
   
   if (texte == nouveau)
   {
   	QString pseudo = QInputDialog::getText(this, "Pseudo","pseudo");
   	utilisateur Bapt(pseudo);
   	if (emetteur == this->bouton1)
   	{ 
   		Bapt.sauverUtilisateur(1); 
   		bouton1 = new QPushButton(pseudo,this);
	    	bouton1->setFixedSize (this->largeurFenetre-25,(this->hauteurFenetre-100)/5);
	    	bouton1->setFont(QFont("", 40, QFont::Bold));
	    	connect(bouton1, SIGNAL(clicked()), this, SLOT(gestionSession()));
   	}
   	if (emetteur == this->bouton2)
   	{ 
   		Bapt.sauverUtilisateur(2);
   		bouton2 = new QPushButton(pseudo,this);
	    	bouton2->setFixedSize (this->largeurFenetre-25,(this->hauteurFenetre-100)/5);
	    	bouton2->setFont(QFont("", 40, QFont::Bold));
	    	connect(bouton2, SIGNAL(clicked()), this, SLOT(gestionSession()));
   	}
   	if (emetteur == this->bouton3)
   	{ 
   		Bapt.sauverUtilisateur(3); 
   		bouton3 = new QPushButton(pseudo,this);
	    	bouton3->setFixedSize (this->largeurFenetre-25,(this->hauteurFenetre-100)/5);
	    	bouton3->setFont(QFont("", 40, QFont::Bold));
	    	connect(bouton3, SIGNAL(clicked()), this, SLOT(gestionSession()));
   	}
   	if (emetteur == this->bouton4)
   	{
   		Bapt.sauverUtilisateur(4);
   	   	bouton4 = new QPushButton(pseudo,this);
   	   	bouton4->setFixedSize (this->largeurFenetre-25,(this->hauteurFenetre-100)/5);
	    	bouton4->setFont(QFont("", 40, QFont::Bold));
	    	connect(bouton4, SIGNAL(clicked()), this, SLOT(gestionSession()));
   	} 
   	
    	window->close();
    	window = new QWidget;
    	layoutPrincipal = new QVBoxLayout(this);
    	layoutPrincipal->addWidget(bouton1);
    	layoutPrincipal->addWidget(bouton2);
    	layoutPrincipal->addWidget(bouton3);
    	layoutPrincipal->addWidget(bouton4);
    	layoutPrincipal->addWidget(quit);
    	    	connect(bouton4, SIGNAL(clicked()), this, SLOT(gestionSession()));
    	window->setLayout(layoutPrincipal);
    	window->showFullScreen();
    	
   	
	
   	  	
   }
   else
   {
   	QObject * emetteurA = sender();
   	QPushButton * emetteur = qobject_cast<QPushButton*>(emetteurA);
   	QString texte = emetteur->text();
   	
   	utilisateur joueur(texte);
   	menuUtilisateur menuJoueur(this,joueur);
   	
   	window->close();
   	this->close(); 

   }
}
