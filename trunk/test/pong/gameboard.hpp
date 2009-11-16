#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>

class GameBoard : public QWidget
{
public:
	GameBoard(QWidget *parent = 0);
private:
	void paintEvent(QPaintEvent *even);
	void paintBlock(QPainter &painter);
	void paintBall(QPainter &painter);
	
}
;

#endif
