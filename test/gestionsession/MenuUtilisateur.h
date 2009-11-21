#ifndef MENUUTILISATEUR_H
#define MENUUTILISATEUR_H

#include <QtGui>
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QFile>
#include <QString>
#include "MenuSessions.h"
#include "Utilisateur.h"

class MenuUtilisateur : QWidget
{
	Q_OBJECT
	
protected:
	// Utilisateur concerné
	Utilisateur joueur;
	
	// Widgets d'affichage
	QWidget *window;
	QLabel *affichagePseudo;
	QPushButton *retourMenu;
	QPushButton *quitter;
public:
	// Constructeur de la classe
	MenuUtilisateur(QWidget *parent, Utilisateur joueurA);

// Déclaration des slots
public slots:
	void a();
};

#endif
