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
	Statistiques(Utilisateur *j, QWidget *parent=0);
private :
	Utilisateur *user;
  
	QLabel *pseudo;
	QLabel *progression;
	QLabel *categories[4];
	QLabel *playtime;
	QLabel *parties;
	QPushButton *quit;
		
	QVBoxLayout *layoutPrincipal;
};

#endif
