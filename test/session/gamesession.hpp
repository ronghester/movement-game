#ifndef GAMESESSION_H
#define GAMESESSION_H

#include <QDebug>
#include <QWidget>

#include "startwindow.hpp"
#include "userwindow.hpp"
#include "user.hpp"
#include "gamewindow.hpp"

class GameSession : public QObject
{
Q_OBJECT
public:
	GameSession();
	void launch();
	void center_widget(QWidget *widget);
public slots:
	void show_user(QString username);
	void start_game(QGraphicsScene *scn);
private:
	StartWindow *start;
	UserWindow *userwindow;
	User *user;
};

#endif
