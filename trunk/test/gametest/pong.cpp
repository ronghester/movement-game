#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>

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
	
	this->setFocusItem(p1);

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
		this->ball->moveBy(PADDLE*dx*0.1, PADDLE*dy*0.1);
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
		x2 = 1;
		break;
	case (Qt::Key_Q):
		x2 = -1;
		break;
	default:
		x = 0;
		x2 = 0;
		break;
	}

	// TODO : find a smarter way
	if (p1->pos().y() < 0) { 
		this->p1->setPos(PADDLE, 0);
	} else if (p1->pos().y()+PADDLE*3 > HEIGHT) {
		this->p1->setPos(PADDLE, HEIGHT-PADDLE*3);
	} else {
		this->p1->moveBy(0, PADDLE*x);
	}

	if (p2->pos().y() < 0) { 
		this->p2->setPos(WIDTH-PADDLE*2, 0);
	} else if (p2->pos().y()+PADDLE*3 > HEIGHT) {
		this->p2->setPos(WIDTH-PADDLE*2, HEIGHT-PADDLE*3);
	} else {
		this->p2->moveBy(0, PADDLE*x2);
	}

}

void
Pong::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
	mouseLogger();
	int x = 1;
	if(e->scenePos().y() <= p1->scenePos().y()) {
		x = -1;
	}
	this->p1->moveBy(0, PADDLE*0.1*x);
}

void 
Pong::mouseLogger(QGraphicsSceneMouseEvent *e)
{
	static int xmax = 0;
	static int xmin = 0;
	static int ymax = 0;
	static int ymin = 0;

	int x = e->scenePos().x();
	int y = e->scenePos().y();

	if (x < xmin) xmin = x;
	if (x > xmax) xmax = x;
	if (y < ymin) ymin = y;
	if (y > ymax) ymax = y;
}
