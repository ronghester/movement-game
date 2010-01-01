#ifndef PONG_H
#define PONG_H

#include <QGraphicsScene>
#include <QGraphicsItem>

class Pong : public QGraphicsScene
{
public:
	Pong();
protected:
	void keyPressEvent(QKeyEvent *e);
private:
	QGraphicsRectItem *p1, *p2;
	QGraphicsEllipseItem *ball;
	int score1, score2;
};

#endif
