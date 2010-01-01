#include <QDebug>
#include <QKeyEvent>

#include "pong.hpp"

#define WIDTH 600
#define HEIGHT (WIDTH/4*3)
#define PADDLE (WIDTH/15)

Pong::Pong()
{
	this->setSceneRect(0, 0, WIDTH, HEIGHT);
	this->p1 = new QGraphicsRectItem(0, 0,
					 PADDLE,
					 PADDLE*3);
	this->p2 = new QGraphicsRectItem(0, 0,
					 PADDLE,
					 PADDLE*3);

	this->p1->setPos(PADDLE, (HEIGHT-PADDLE*3)/2);
	this->p2->setPos(WIDTH-PADDLE*2, (HEIGHT-PADDLE*3)/2);
	this->p1->setBrush(QBrush(Qt::red));
	this->p2->setBrush(QBrush(Qt::blue));

	/* ball */
	this->ball = new QGraphicsEllipseItem(0, 0, PADDLE, PADDLE);
	this->ball->setPos((WIDTH-PADDLE)/2, (HEIGHT-PADDLE)/2);
	this->ball->setBrush(QBrush(Qt::black));
	
	this->dx = -1;
	this->dy = 0;

	QTimeLine *timer = new QTimeLine(5000);
	timer->setFrameRange(0, 100);
	connect(timer,
		SIGNAL(valueChanged(int)),
		this,
		SLOT(value_changed(int)));
	this->addItem(ball);
	this->addItem(p1);
	this->addItem(p2);
	timer->start();
}
void
Pong::value_changed(int)
{
	if (timer->currentValue()==timer->duration()) {
		timer->setLoopCount(1);
	}
	this->ball->moveBy(PADDLE*dx, 0*dy);
}

void
Pong::keyPressEvent(QKeyEvent *e)
{
	static int x;
	switch(e->key()) {
	case (Qt::Key_Up):
		x = -1;
		break;
	case (Qt::Key_Down):
		x = 1;
		break;
	default:
		x = 0;
		break;
	}

	/*	if(p1->y() >= PADDLE*2 && */
	/*	p1->y() + PADDLE*3 <= HEIGHT) */
	/* TODO : edge detection */
	this->p1->moveBy(0, PADDLE*x);
}
