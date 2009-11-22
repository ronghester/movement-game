#include "menuutilisateur.hpp"

#include <iostream>

MenuUtilisateur::MenuUtilisateur(QWidget *parent, Utilisateur joueurA) : QWidget(parent), joueur(joueurA)
{
	// On charge la configuration de l'utilisateur.
	joueur.charger_utilisateur();
	
	// Création de la fenêtre.
	window = new QWidget;
	
	// Création des éléments graphiques.
	affichagePseudo = new QLabel(joueur.obtenir_pseudo(),this);
	retourMenu = new QPushButton("Menu Principal",this);
	quitter = new QPushButton("Quitter", this);
	
	// Connection des signaux.
	connect(retourMenu, SIGNAL(clicked()), this, SLOT(a()));
	connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
	
	// Création et remplissage du layout.
	QHBoxLayout *layoutPrincipal = new QHBoxLayout(this);
	layoutPrincipal->addWidget(affichagePseudo);
    	layoutPrincipal->addWidget(retourMenu);
    	layoutPrincipal->addWidget(quitter);
    	window->setLayout(layoutPrincipal);
    	// Affichage de la fenêtre.
	window->show();
}

//Slots
void MenuUtilisateur::a()
{
	std::cout << "Debug\n";
}
