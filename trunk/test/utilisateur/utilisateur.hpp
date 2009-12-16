#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QSettings>

class Utilisateur
{
public:
	Utilisateur(QString pseudo);

	void creerUtilisateur();
	// Edition des propriétés
	void modifierParties(int p);
	void modifierTemps(int t);
	void modifierNiveauC1(int n);
	void modifierNiveauC2(int n);
	void modifierNiveauC3(int n);
	void modifierNiveauC4(int n);
	// Recupération des propriétés
	QString obtenirPseudo();
	int obtenirParties();
	int obtenirTemps();
	int obtenirNiveauC1();
	int obtenirNiveauC2();
	int obtenirNiveauC3();
	int obtenirNiveauC4();
private:
	// Propriétés
	QString fichierUtilisateur;
	QString pseudo;
};

#endif
