#include <QDebug>
#include <QKeyEvent>
#include "player.hpp"

Player::Player(int x, int y, int width, int height, QBrush brush)
{
	this->setRect(x, y, width, height);
	this->setBrush(brush);
}

void Player::keyPressEvent(QKeyEvent *e)
{
	qDebug()<<"Key up";
}
