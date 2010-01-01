#include "userwindow.hpp"
#include "user.hpp"

#include <QString>
#include <QDebug>
#include <QPen>

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

	int diagramWidth = diagram->width()/2;
	int diagramHeight = diagram->height()/2;

	QGraphicsLineItem *x  = new QGraphicsLineItem(diagramWidth, 0, diagramWidth, diagramHeight*2);
	QGraphicsLineItem *y = new QGraphicsLineItem(0, diagramHeight, diagramWidth*2, diagramHeight);

	QGraphicsLineItem *l1, *l2, *l3, *l4;

	int cat1 = user->get_property("category1");
	int cat2 = user->get_property("category2");
	int cat3 = user->get_property("category3");
	int cat4 = user->get_property("category4");

	l1 = new QGraphicsLineItem(diagramWidth, diagramHeight*(1-0.1*cat1), diagramWidth*(1+0.1*cat2), diagramHeight);
	l2 = new QGraphicsLineItem(diagramWidth*(1+0.1*cat2), diagramHeight, diagramWidth, diagramHeight*(1+0.1*cat3));
	l3 = new QGraphicsLineItem(diagramWidth, diagramHeight*(1+0.1*cat3), diagramWidth*(1-0.1*cat4), diagramHeight);
	l4 = new QGraphicsLineItem(diagramWidth*(1-0.1*cat4), diagramHeight, diagramWidth, diagramHeight*(1-0.1*cat1));

	group->addToGroup(l1);
	group->addToGroup(l2);
	group->addToGroup(l3);
	group->addToGroup(l4);
	// for (int x = 1; x<5; ++x) {
	// 	QGraphicsLineItem *line = new QGraphicsLineItem();
	// 	QString str;
	// 	str.setNum(x);

	// 	int value1 = user->get_property("category"+str);    // get score of cat(n)
	// 	int value2 = user->get_property("category"+str.setNum(x+1));
	// 	if (x<4) {
	// 		value2 = user->get_property("category"+str);
	// 	} else {
	// 		value2 = user->get_property("category1");
	// 	}
		
	// 	if (x==1) {
	// 		qDebug("Are we in ?");
	// 		line->setLine(diagramWidth, diagramHeight*(1-value1), diagramHeight, diagramWidth*(1+value2));
	// 	} else if (x==2) {
	// 		line->setLine(diagramWidth*(1+value1), diagramHeight, diagramHeight*(1+value2), diagramWidth);
	// 	} else if (x==3) {
	// 		line->setLine(diagramWidth, diagramHeight*(1+value1), diagramWidth*(1-value2), diagramHeight);
	// 	} else if (x==4) {
	// 		line->setLine(diagramWidth*(1-value1), diagramHeight, diagramWidth, diagramHeight*(1-value2));
	// 	}
 
	// 	group->addToGroup(line);
	// }
	
	group->addToGroup(x);
	group->addToGroup(y);

	return group;
}
