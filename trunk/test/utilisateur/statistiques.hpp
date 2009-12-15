#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QSettings>
#include "utilisateur.hpp"

class Statistiques : public QWidget
{
	public :
		// Constructeur
		Statistiques(Utilisateur *j, QWidget *parent=NULL);
	private :
		// Joueur
		Utilisateur *joueur;
	
		// Widgets
		QLabel *labelPseudo;
		QLabel *labelProgression;
		QLabel *labelCategories[4];
		QLabel *labelTemps;
		QLabel *labelParties;
		QPushButton *boutonQuitter;
		
		// Layout
		QVBoxLayout *layoutPrincipal;
};

#endif
