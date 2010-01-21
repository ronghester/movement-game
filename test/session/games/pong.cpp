#include <QDebug>
#include <QKeyEvent>

#include "pong.hpp"

#define WIDTH 400
#define HEIGHT (WIDTH/4*3)
#define PADDLE (WIDTH/10)

Pong::Pong()
{
	gameinfo = new QStringList(QStringList()
				   << "endurance"						      
				   << "Pong"
				   << "The famous Pong game"
				   << "Stéphane Maniaci"
				   << "0.1");
	this->setSceneRect(0, 0, WIDTH, HEIGHT);
	this->p1 = new QGraphicsRectItem(PADDLE,
					 HEIGHT/2,
					 PADDLE,
					 PADDLE*3);
	this->p2 = new QGraphicsRectItem(HEIGHT - PADDLE*2,
					 HEIGHT/2 - PADDLE/2,
					 PADDLE,
					 PADDLE*3);
	this->addItem(p1);
	this->addItem(p2);
}

void
Pong::keyPressEvent(QKeyEvent *e)
{
	if (e->key()==Qt::Key_Up)
	{
		qDebug()<<"Touche up !";
	}
}

QStringList
Pong::plugin_info() 
{
	return *gameinfo;
}


Q_EXPORT_PLUGIN2(sg_pong, Pong)
