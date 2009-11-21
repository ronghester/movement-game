#include <QPainter>

#include "ball.hpp"

Ball::Ball(QWidget *parent)
	:x(0),y(0)
{
}

void Ball::paintEvent (QPaintEvent *event)
{
	QPainter *painter = new QPainter(this);
	
	painter->setPen(Qt::red);
	painter->drawEllipse(20,20,100, 100);	
}

bool Ball::inScreen()
{
	return true;
}

       
