#include "statistiques.hpp"


Statistiques::Statistiques(Utilisateur *j, QWidget *parent) : QWidget(parent), joueur(j)
{	
	pseudo = new QLabel(joueur->getPseudo());
	playtime = new QLabel("Playtime : " + QString::number(joueur->obtenirTemps()) + " hours.");
	games = new QLabel("Game sessions : " + QString::number(joueur->obtenirParties()));
	progression = new QLabel("Progression : ");
	categories[0] = new QLabel("Category 1 :" + String::number(joueur->obtenirNiveauC1()) + "%");
	categories[1] = new QLabel("Category 2 :" + String::number(joueur->obtenirNiveauC2()) + "%");
	categories[2] = new QLabel("Category 3 :" + String::number(joueur->obtenirNiveauC3()) + "%");
	categories[3] = new QLabel("Category 4 :" + String::number(joueur->obtenirNiveauC4()) + "%");
	quit = new QPushButton("Quit", this);
	
	connect(quit, SIGNAL(clicked()), this, SLOT(close()));
	
	layoutPrincipal = new QVBoxLayout();
	layoutPrincipal -> addWidget(labelPseudo);
	layoutPrincipal -> addWidget(labelTemps);
	layoutPrincipal -> addWidget(labelParties);
	layoutPrincipal -> addWidget(labelProgression);
	for (int i=0; i<4; i++)
	  layoutPrincipal -> addWidget(categories[i]);
	layoutPrincipal -> addWidget(boutonQuitter);
	this -> setLayout(layoutPrincipal);
}
