#ifndef PONG_H
#define PONG_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimeLine>
#include <QMouseEvent>

class Pong : public QGraphicsScene
{
Q_OBJECT
public:
	Pong();
	void mouseLogger(QGraphicsSceneMouseEvent *e);
protected:
	void keyPressEvent(QKeyEvent *e);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
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
