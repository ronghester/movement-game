#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
#include <QBrush>

class Player : public QGraphicsRectItem
{
public:
	Player(int x, int y, int width, int height, QBrush brush);
	void keyPressEvent(QKeyEvent *e);
	
};

	

#endif
