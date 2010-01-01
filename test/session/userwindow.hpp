#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBoxLayout>
#include <QGraphicsItemGroup>

#include "user.hpp"

class UserWindow : public QWidget
{
Q_OBJECT
public:
	UserWindow(User *usr, QWidget *parent = 0);
	QGraphicsItemGroup *draw_diagram();
public slots:
	void show_stats();
private:
	User *user;

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
