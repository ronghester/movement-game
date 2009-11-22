#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QString>
#include <iostream>
#include <QFile>
#include <QTextStream>

class Utilisateur
{
protected:
	// Attributs propre a un utilisateur :
	QString pseudo;		// Le pseudo
	int difficulte;		// La difficulté

public:
	// Constructeur de la classe.
	Utilisateur(QString pseudo);
	// Permet d'enregistrer la configuration de l'utilisateur.
	void enregistrer_utilisateur(int place);
	// Permet de charger la configuration de l'utilisateur.
	void charger_utilisateur();
	// Permet d'obtenir le pseudo de l'utilisateur.
	QString obtenir_pseudo();
	// Permet d'obtenir la difficulte de l'utilisateur.
	int obtenir_difficulte();
};

#endif
