#ifndef GAMESESSION_H
#define GAMESESSION_H

#include <QDebug>
#include <QWidget>

#include "startwindow.hpp"
#include "profilewindow.hpp"
#include "userwindow.hpp"

class GameSession : public QObject
{
Q_OBJECT
public:
	GameSession();
	void launch();
	void center_widget(QWidget *widget);
public slots:
	void show_profiles();
	void show_user(QString username);
private:
	StartWindow *start;
	ProfileWindow *profiles;
	UserWindow *userwindow;
};

#endif
