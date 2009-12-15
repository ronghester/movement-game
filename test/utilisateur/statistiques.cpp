#include "statistiques.hpp"


Statistiques::Statistiques(Utilisateur *j, QWidget *parent) : QWidget(parent), joueur(j)
{	
	// Création des widgets
	QString convertion;
	labelPseudo = new QLabel(joueur->obtenirPseudo() +" :");
	labelTemps = new QLabel("Temps de jeu : " + convertion.number(joueur->obtenirTemps()) + " heures");
	labelParties = new QLabel("Nombre de parties : " + convertion.number(joueur->obtenirParties()));
	labelProgression = new QLabel("Progression : ");
	labelCategories[0] = new QLabel("   Categorie 1 :" + convertion.number(joueur->obtenirNiveauC1()) + "%");
	labelCategories[1] = new QLabel("   Categorie 2 :" + convertion.number(joueur->obtenirNiveauC2()) + "%");
	labelCategories[2] = new QLabel("   Categorie 3 :" + convertion.number(joueur->obtenirNiveauC3()) + "%");
	labelCategories[3] = new QLabel("   Categorie 4 :" + convertion.number(joueur->obtenirNiveauC4()) + "%");
	boutonQuitter = new QPushButton("Quitter",this);
	
	// Connexion des signaux
	connect(boutonQuitter, SIGNAL(clicked()), this, SLOT(close()));
	
	// Organisation des layouts
	layoutPrincipal = new QVBoxLayout();
		layoutPrincipal -> addWidget(labelPseudo);
		layoutPrincipal -> addWidget(labelTemps);
		layoutPrincipal -> addWidget(labelParties);
		layoutPrincipal -> addWidget(labelProgression);
		for (int i=0; i<4; i++)
			layoutPrincipal -> addWidget(labelCategories[i]);
		layoutPrincipal -> addWidget(boutonQuitter);
	this -> setLayout(layoutPrincipal);
}
