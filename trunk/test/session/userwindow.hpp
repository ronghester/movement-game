#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBoxLayout>

#include "user.hpp"

class UserWindow : public QWidget
{
Q_OBJECT
public:
	UserWindow(User *user, QWidget *parent = 0);
private:
	QLabel *welcome;

	QPushButton *play;
	QPushButton *stats;
	QPushButton *multiplayer;
	QPushButton *quit;

	QGraphicsScene *diagram;
	QGraphicsView *view;

	QHBoxLayout *menubar;
	QVBoxLayout *layout;
};

#endif
