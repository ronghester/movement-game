#include "userscreen.hpp"


Userscreen::Userscreen(QString pseudo, QWidget *parent) : QWidget(parent)
{
	// Creation du joueur
	joueur = new Utilisateur(pseudo);
	
	// Création des widgets
	labelAccueil = new QLabel("Bonjour " + joueur->obtenirPseudo());
	boutonJouer = new QPushButton("Jouer",this);
	boutonStats = new QPushButton("Statistiques",this);
	boutonQuitter = new QPushButton("Quitter",this);
	categories[0] = new QPushButton("Categorie 1", this);
	categories[1] = new QPushButton("Categorie 2", this);
	categories[2] = new QPushButton("Categorie 3", this);
	categories[3] = new QPushButton("Categorie 4", this);
	for (int i=0; i<4; i++)	
		categories[i]->setFixedSize (150,25);
	
	// Scene graphique
	scene = new QGraphicsScene;
	scene->setSceneRect(-100, -100, 200, 200);
	axes[0] = new QLine(0,0,0,-100);
	liaisons[0] = new QLine(0,-joueur->obtenirNiveauC1(),joueur->obtenirNiveauC2(),0 );
	axes[1] = new QLine(0,0,100,0);
	liaisons[1] = new QLine(joueur->obtenirNiveauC2(),0,0,joueur->obtenirNiveauC3());
	axes[2] = new QLine(0,0,0,100);
	liaisons[2] = new QLine(0,joueur->obtenirNiveauC3(),-joueur->obtenirNiveauC4(),0);
	axes[3] = new QLine(0,0,-100,0);
	liaisons[3] = new QLine(-joueur->obtenirNiveauC4(),0,0,-joueur->obtenirNiveauC1());
	for (int i=0; i<4; i++)
		scene->addLine(*axes[i]);
	for (int i=0; i<4; i++)
		scene->addLine(*liaisons[i]);
 	view = new QGraphicsView(scene);

	// Connexion des signaux
	connect(boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
	connect(boutonStats, SIGNAL(clicked()), this, SLOT(ouverture_statistiques()));

	// Organisation des layouts
	layoutBoutons = new QHBoxLayout();
		layoutBoutons -> addWidget(boutonJouer);
		layoutBoutons -> addWidget(boutonStats);
		layoutBoutons -> addWidget(boutonQuitter);
	centrageBoutonA = new QHBoxLayout();
		centrageBoutonA -> addStretch();
		centrageBoutonA -> addWidget(categories[0]);
		centrageBoutonA -> addStretch();
	centrageBoutonB = new QHBoxLayout();
		centrageBoutonB -> addStretch();
		centrageBoutonB -> addWidget(categories[2]);
		centrageBoutonB -> addStretch();
	sceneHorizontal = new QHBoxLayout();
		sceneHorizontal -> addWidget(categories[3]);
		sceneHorizontal -> addWidget(view);
		sceneHorizontal -> addWidget(categories[1]);
	sceneVertical = new QVBoxLayout();
		sceneVertical -> addLayout(centrageBoutonA);
		sceneVertical -> addLayout(sceneHorizontal);
		sceneVertical -> addLayout(centrageBoutonB);
	layoutPrincipal = new QVBoxLayout();
		layoutPrincipal->addWidget(labelAccueil);
		layoutPrincipal->addLayout(layoutBoutons);
		layoutPrincipal->addLayout(sceneVertical);
    	this -> setLayout(layoutPrincipal);
}

// Slots
void Userscreen::ouverture_statistiques()
{
	Statistiques *stats = new Statistiques(joueur);
	stats->show();
}
