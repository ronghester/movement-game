#include <QtGui>
#include <QLayout>
#include <QFile>
#include <QString>
#include <iostream>
#include "menuSessions.h"
#include "menuUtilisateur.h"
#include <QDebug>

menuUtilisateur::menuUtilisateur(QWidget *parent, utilisateur joueurA) : QWidget(parent), joueur(joueurA)
{
	joueurA.chargerUtilisateur();
	
	window = new QWidget;
	
	affichagePseudo = new QLabel(joueurA.getPseudo(),this);
	retourMenu = new QPushButton("Menu Principal",this);
	quitter = new QPushButton("Quitter", this);
	
	connect(retourMenu, SIGNAL(clicked()), this, SLOT(retourMenuSessions()));
	connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
	
	QHBoxLayout *layoutPrincipal = new QHBoxLayout(this);
	layoutPrincipal->addWidget(affichagePseudo);
    	layoutPrincipal->addWidget(retourMenu);
    	layoutPrincipal->addWidget(quitter);
    	
    	window->setLayout(layoutPrincipal);
	window->show();
}

/* Slots */
void menuUtilisateur::retourMenuSessions()
{
}
