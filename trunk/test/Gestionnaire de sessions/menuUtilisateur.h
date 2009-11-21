#ifndef MENUUTILISATEUR_H
#define MENUUTILISATEUR_H

#include <QPushButton>
#include <QLayout>
#include <QLabel>
#include <QWidget>
#include "utilisateur.h"

class menuUtilisateur : public QWidget
{
	Q_OBJECT

public:
    menuUtilisateur(QWidget *parent, utilisateur joueurA);
    
/* Déclaration des slots */
public slots:
    void retourMenuSessions();
    
protected:
    utilisateur joueur;
    QWidget *window;
    QLabel *affichagePseudo;
    QPushButton *retourMenu;
    QPushButton *quitter;
    
};

#endif
