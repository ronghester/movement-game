#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsView>

#include "gamesession.hpp"

class GameWindow : public QWidget
{
public:
	GameWindow(QWidget *parent = 0);
private:
	QPushButton *quitbutton;
	QVBoxLayout *layout;
	GameSession *session;
	QGraphicsView *view;
}
;

#endif
