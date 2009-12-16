#include "utilisateur.hpp"

Utilisateur::Utilisateur (QString p)
{
	pseudo = p;
	fichierUtilisateur = ("users/" + pseudo + ".ini");
}

void Utilisateur::creerUtilisateur()
{
	QSettings *fichier = new QSettings(fichierUtilisateur, QSettings::IniFormat);
	fichier->setValue("pseudo", pseudo);
	fichier->setValue("parties", 0);
	fichier->setValue("temps", 0);
	fichier->setValue("niveauCategorie1", 0);
	fichier->setValue("niveauCategorie2", 0);
	fichier->setValue("niveauCategorie3", 0);
	fichier->setValue("niveauCategorie4", 0);
}

void Utilisateur::modifierParties(int p)
{
	QSettings *fichier = new QSettings(fichierUtilisateur, QSettings::IniFormat);
	fichier->setValue("parties", p);
}
void Utilisateur::modifierTemps(int t)
{
	QSettings *fichier = new QSettings(fichierUtilisateur, QSettings::IniFormat);
	fichier->setValue("temps", t);
}
void Utilisateur::modifierNiveauC1(int n)
{
	QSettings *fichier = new QSettings(fichierUtilisateur, QSettings::IniFormat);
	fichier->setValue("niveauCategorie1", n);
}
void Utilisateur::modifierNiveauC2(int n)
{
	QSettings *fichier = new QSettings(fichierUtilisateur, QSettings::IniFormat);
	fichier->setValue("niveauCategorie2", n);
}
void Utilisateur::modifierNiveauC3(int n)
{
	QSettings *fichier = new QSettings(fichierUtilisateur, QSettings::IniFormat);
	fichier->setValue("niveauCategorie3", n);
}
void Utilisateur::modifierNiveauC4(int n)
{
	QSettings *fichier = new QSettings(fichierUtilisateur, QSettings::IniFormat);
	fichier->setValue("niveauCategorie4", n);
}

QString Utilisateur::obtenirPseudo()
{
	QSettings *fichier = new  QSettings(fichierUtilisateur, QSettings::IniFormat);
	return (fichier->value("pseudo").toString());
}
int Utilisateur::obtenirParties()
{
	QSettings *fichier = new  QSettings(fichierUtilisateur, QSettings::IniFormat);
	return (fichier->value("parties").toInt());
}
int Utilisateur::obtenirTemps()
{
	QSettings *fichier = new  QSettings(fichierUtilisateur, QSettings::IniFormat);
	return fichier->value("temps").toInt();
}
int Utilisateur::obtenirNiveauC1()
{
	QSettings *fichier = new  QSettings(fichierUtilisateur, QSettings::IniFormat);
	return fichier->value("niveauCategorie1").toInt();
}
int Utilisateur::obtenirNiveauC2()
{
	QSettings *fichier = new  QSettings(fichierUtilisateur, QSettings::IniFormat);
	return fichier->value("niveauCategorie2").toInt();
}
int Utilisateur::obtenirNiveauC3()
{
	QSettings *fichier = new  QSettings(fichierUtilisateur, QSettings::IniFormat);
	return fichier->value("niveauCategorie3").toInt();
}
int Utilisateur::obtenirNiveauC4()
{
	QSettings *fichier = new  QSettings(fichierUtilisateur, QSettings::IniFormat);
	return fichier->value("niveauCategorie4").toInt();
}
