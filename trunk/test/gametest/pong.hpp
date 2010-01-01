#ifndef PONG_H
#define PONG_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimeLine>

class Pong : public QGraphicsScene
{
public:
	Pong();
protected:
	void keyPressEvent(QKeyEvent *e);
public slots:
	void value_changed(int);
private:
	QGraphicsRectItem *p1, *p2;
	QGraphicsEllipseItem *ball;
	QTimeLine *timer;
	int dx, dy;
	int score1, score2;
};

#endif
