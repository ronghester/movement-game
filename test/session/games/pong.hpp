#ifndef PONG_H
#define PONG_H

#include <QGraphicsScene>
#include <QGraphicsItem>

#include <gameinterface.hpp>

class Pong : public QGraphicsScene,
	     public GameInterface
{
Q_OBJECT
Q_INTERFACES(GameInterface)

public:
	QStringList plugin_info();
	Pong();
protected:
	void keyPressEvent(QKeyEvent *e);
private:
	QStringList *gameinfo;
	QGraphicsRectItem *p1, *p2;
	QGraphicsEllipseItem *ball;
	int score1, score2;
};

#endif
