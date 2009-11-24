#include "gamesession.hpp"
#include <QDebug>

GameSession::GameSession()
{
	this->setSceneRect(0, 0, 200, 200);
	this->p1 = new QGraphicsRectItem(0, 0, 50, 50);
	this->p1->setBrush(QBrush(Qt::red));
	this->addItem(this->p1);
}
