#include "userwindow.hpp"
#include "user.hpp"

#include <QString>
#include <QDebug>

// TODO : move includes to header
#include <QGraphicsItem>

UserWindow::UserWindow(User *user, QWidget *parent)
	:QWidget(parent)
{
	this->setWindowTitle("Your control panel");
	QString username = user->get_name();

	welcome = new QLabel("Welcome <b>"+ username +"</b>");

	play = new QPushButton("Play");
	stats = new QPushButton("Stats");
	multiplayer = new QPushButton("Multiplayer");
	quit = new QPushButton("Quit");

	// TODO : adapt size to screen size
	diagram = new QGraphicsScene(0, 0, 500, 400);
	view = new QGraphicsView(diagram);

	diagram->addItem(draw_diagram(user));

	menubar = new QHBoxLayout();
	layout = new QVBoxLayout(this);

	menubar->addWidget(play);
	menubar->addWidget(stats);
	menubar->addWidget(multiplayer);
	menubar->addWidget(quit);

	layout->addWidget(welcome);
	layout->addLayout(menubar);
	layout->addWidget(view);
	this->show();
}

QGraphicsItemGroup *
UserWindow::draw_diagram(User *user)
{
	QGraphicsItemGroup *group = new QGraphicsItemGroup();

	QGraphicsLineItem *x  = new QGraphicsLineItem(50, 0, 50, 100);
	QGraphicsLineItem *y = new QGraphicsLineItem(0, 50, 100, 50);

	group->addToGroup(x);
	group->addToGroup(y);

	return group;
}
