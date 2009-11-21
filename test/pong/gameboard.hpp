#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QGraphicsScene>

class GameBoard : public QGraphicsScene
{
public:
	GameBoard(const QRectF &rect, QWidget *parent = 0);
private:
	void paintEvent(QPaintEvent *even);
	void paintBlock(QPainter &painter);
	void paintBall(QPainter &painter);
	
}
;

#endif
