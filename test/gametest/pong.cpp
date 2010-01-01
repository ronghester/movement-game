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
	this->dy = -1;

	QTimeLine *timer = new QTimeLine(5000);
	timer->setFrameRange(0, 100);
	this->addItem(ball);
	this->addItem(p1);
	this->addItem(p2);
	timer->setLoopCount(10000);
	timer->start();
	connect(timer,
		SIGNAL(frameChanged(int)),
		this,
		SLOT(value_changed(int)));
}

void
Pong::value_changed(int)
{
        /* do we collide ? */
	if (ball->x()>=PADDLE*2 && ball->x()<=WIDTH-PADDLE*2) {
		if (ball->collidesWithItem(p1) || ball->collidesWithItem(p2)) {
			dx = -dx;
		} else if (ball->y()<=0 || ball->y()>=HEIGHT-PADDLE) {
			dy = -dy;
		}
		this->ball->moveBy(PADDLE*dx*0.005, PADDLE*dy*0.005);
	}
}

void
Pong::keyPressEvent(QKeyEvent *e)
{
	int x = 0;
	int x2 = 0;
	switch(e->key()) {
	case (Qt::Key_Up):
		x = -1;
		break;
	case (Qt::Key_Down):
		x = 1;
		break;
	case (Qt::Key_A):
		x2 = -1;
		break;
	case (Qt::Key_Q):
		x2 = 1;
		break;
	default:
		x = 0;
		x2 = 0;
		break;
	}

	/*	if(p1->y() >= PADDLE*2 && */
	/*	p1->y() + PADDLE*3 <= HEIGHT) */
	/* TODO : edge detection */
	this->p1->moveBy(0, PADDLE*x);
	this->p2->moveBy(0, PADDLE*x2);
}
