#include "userwindow.hpp"
#include "user.hpp"

#include <QString>
#include <QDebug>

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

