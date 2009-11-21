#ifndef MENUSESSIONS_H
#define MENUSESSIONS_H

#include <QtGui>
#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QFile>
#include <QString>
#include "Utilisateur.h"
#include "MenuUtilisateur.h"

class MenuSessions : QWidget
{
	Q_OBJECT

protected:
	// Dimensions de l'espace de l'utilisateur
	int largeurFenetre;
	int hauteurFenetre;
	// Widgets d'affichage
	QWidget *window;
	QPushButton *boutons[4];
	QPushButton *quit;
	QVBoxLayout *layoutPrincipal;
public:
	// Constructeur de la classe
	MenuSessions(QWidget *parent = 0);

// Déclaration des slots
public slots:
	void gestion_session();


};

#endif
