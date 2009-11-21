#ifndef MENUSESSIONS_H
#define MENUSESSIONS_H

#include <QPushButton>
#include <QLayout>
#include <QWidget>

class menuSessions : QWidget
{
    Q_OBJECT

public:
    menuSessions(QWidget *parent = 0);

/* Déclaration des slots */
public slots:
    void gestionSession();

protected:
	QWidget *window;
	int largeurFenetre;
	int hauteurFenetre;
    QPushButton *bouton1;
    QPushButton *bouton2;
    QPushButton *bouton3;
    QPushButton *bouton4;
    QPushButton *quit;
    QVBoxLayout *layoutPrincipal;
};

#endif
