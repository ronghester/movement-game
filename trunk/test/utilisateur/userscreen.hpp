#ifndef USERSCREEN_H
#define USERSCREEN_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSettings>
#include "statistiques.hpp"
#include "utilisateur.hpp"

class Userscreen : public QWidget
{
	Q_OBJECT	
	
	public :
		// Constructeur
		Userscreen(QString pseudo, QWidget *parent = 0);
		
	private :
		// Joueur
		QString pseudo;
		Utilisateur *joueur;

		// Widgets
		QLabel *labelAccueil;
		QPushButton *boutonJouer;
		QPushButton *boutonStats;
		QPushButton *boutonQuitter;
		QPushButton *categories[4];

		// Scene graphique
		QGraphicsScene *scene;
		QGraphicsView *view;
		QLine *axes[4];
		QLine *liaisons[4];

		// Layouts
		QHBoxLayout *layoutBoutons;
		QVBoxLayout *layoutPrincipal;
		QHBoxLayout *sceneHorizontal;
		QVBoxLayout *sceneVertical;
		QHBoxLayout *centrageBoutonA;
		QHBoxLayout *centrageBoutonB;
	
	// Slots
	public slots:
		void ouverture_statistiques();
};

#endif
