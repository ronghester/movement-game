#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
#include <QBrush>
#include <QPaintEvent>

class Player : public QGraphicsRectItem
{
public:
	Player(int x, int y, int width, int height, QBrush brush);
protected:
	void keyPressEvent(QKeyEvent *e);
	void paintEvent(QPaintEvent *event);
	
};

	

#endif
