#include <QDebug>
#include <QKeyEvent>
#include <QPainter>

#include "player.hpp"

Player::Player(int x, int y, int width, int height, QBrush brush)
{
	this->setRect(x, y, width, height);
	this->setBrush(brush);
	this->setFlags(QGraphicsItem::ItemIsFocusable);
}

void Player::keyPressEvent(QKeyEvent *event)
{
	int x = this->x();
	int y = this->y();
	
	switch (event->key()){
	case Qt::Key_Up:
		y-=10;
		break;
	case Qt::Key_Down:
		y+=10;
		break;
	default:
		break;
	}
	this->setPos(x, y);
}


void Player::paintEvent(QPaintEvent *event)
{
	QPainter *painter = new QPainter();
	painter->setPen(QPen(Qt::red));
	painter->drawText(0, 0, "This is it !");
}
