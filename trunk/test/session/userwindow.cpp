#include "userwindow.hpp"
#include "user.hpp"
#include "pong.hpp"

#include <QApplication>
#include <QGraphicsScene>

#include <QString>
#include <QDebug>
#include <QPen>
#include <QMessageBox>
#include <QDir>
#include <QInputDialog>
#include <QPluginLoader>

/* TODO : cleanup headers */

#include <QGraphicsItem>
#include "gameinterface.hpp"

UserWindow::UserWindow(User *usr, QWidget *parent)
	:QWidget(parent)
{
	user = usr;
	this->setWindowTitle(tr("Your control panel"));
	QString username = user->get_name();

	welcome = new QLabel(tr("Welcome") +" <b>"+ username +"</b>");

	play = new QPushButton(tr("Play"));
	stats = new QPushButton(tr("Stats"));
	multiplayer = new QPushButton(tr("Multiplayer"));
	quit = new QPushButton(tr("Quit"));

	// TODO : adapt size to screen size
	diagram = new QGraphicsScene(0, 0, 500, 400);
	view = new QGraphicsView(diagram);

	// antialiasing
	view->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

	diagram->addItem(draw_diagram());

	menubar = new QHBoxLayout();
	layout = new QVBoxLayout(this);

	menubar->addWidget(play);
	menubar->addWidget(stats);
	menubar->addWidget(multiplayer);
	menubar->addWidget(quit);

	connect(play, SIGNAL(clicked()), this, SLOT(show_games()));
	connect(stats, SIGNAL(clicked()), this, SLOT(show_stats()));
	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

	layout->addWidget(welcome);
	layout->addLayout(menubar);
	layout->addWidget(view);
	this->show();
}

QGraphicsItemGroup *
UserWindow::draw_diagram()
{
	QGraphicsItemGroup *group = new QGraphicsItemGroup();

	int diagramWidth = diagram->width()/2;
	int diagramHeight = diagram->height()/2;

	QGraphicsLineItem *x  = new QGraphicsLineItem(diagramWidth, 0, diagramWidth, diagramHeight*2);
	QGraphicsLineItem *y = new QGraphicsLineItem(0, diagramHeight, diagramWidth*2, diagramHeight);

	QGraphicsLineItem *l1, *l2, *l3, *l4;
	QPen pen(Qt::red, 2);
	
	int cat1 = user->get_property("category1");
	int cat2 = user->get_property("category2");
	int cat3 = user->get_property("category3");
	int cat4 = user->get_property("category4");

	l1 = new QGraphicsLineItem(diagramWidth, diagramHeight*(1-0.1*cat1), diagramWidth*(1+0.1*cat2), diagramHeight);
	l2 = new QGraphicsLineItem(diagramWidth*(1+0.1*cat2), diagramHeight, diagramWidth, diagramHeight*(1+0.1*cat3));
	l3 = new QGraphicsLineItem(diagramWidth, diagramHeight*(1+0.1*cat3), diagramWidth*(1-0.1*cat4), diagramHeight);
	l4 = new QGraphicsLineItem(diagramWidth*(1-0.1*cat4), diagramHeight, diagramWidth, diagramHeight*(1-0.1*cat1));

	l1->setPen(pen); l2->setPen(pen); l3->setPen(pen); l4->setPen(pen);

	group->addToGroup(l1);
	group->addToGroup(l2);
	group->addToGroup(l3);
	group->addToGroup(l4);

	group->addToGroup(x);
	group->addToGroup(y);

	return group;
}

void
UserWindow::show_stats()
{
	QString stats = "<b>" + tr("Games") + " :</b> " + QString::number(user->get_property("games"))+
		"<br><b>" + tr("Play time") + " :</b> " + QString::number(user->get_property("playtime"));
	
	for (int i = 1; i<5; ++i) {
		QString cat = "<br><b>" +tr("Category") + " " + QString::number(i) + "</b>: ";
		cat+= QString::number(user->get_property("category" + QString::number(i))*10) + "%";
		stats += cat;
	}
	QMessageBox::information(0, tr("Your statistics"),
					   stats);

}

void
UserWindow::show_games()
{
	this->hide();
	QDir *cur = new QDir(QDir::currentPath()+"/games/");

	foreach (QString filename, cur->entryList(QDir::Files)) {
		QPluginLoader loader(cur->absoluteFilePath(filename));
		QObject *plugin = loader.instance();
		if(plugin) {
			GameInterface *test = qobject_cast<GameInterface *>(plugin);
			if(test) {
				qDebug()<<"Successfully loaded plugin.";
				qDebug()<< test->plugin_info();
			}
		}
	}

}
/*
	cur->setFilter(QDir::Files);
	bool ok;
	QString gamename = QInputDialog::getItem(0, 
						 tr("Game selection"),
						 tr("Please pick a game"),
						 cur->entryList(),
						 0,
						 false,
						 &ok);	
	
	if(ok) {
		Pong *g = new Pong();
		emit(send_game(g));
	} else {
		this->show();
		}*/
