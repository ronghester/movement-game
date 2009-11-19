#include <QPainter>

#include "ball.hpp"

Ball::Ball(QWidget *parent)
	:x(0),y(0)
{
}

void Ball::paintEvent (QPaintEvent *event)
{
	QPainter *painter;
	painter->setPen(Qt::red);
	painter->drawEllipse(parent.rect(),100, 100);
}

void Ball::inScreen()
{
	return true;
}

       
