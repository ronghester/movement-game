#ifndef GAMESESSION_H
#define GAMESESSION_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>

class GameSession : public QGraphicsScene
{
public:
	GameSession();
private:
	// players
	QGraphicsRectItem *p1, *p2;
		
}
	;

#endif
