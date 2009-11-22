#include <QRectF>
#include <QPainter>
#include "gameboard.hpp"

GameBoard::GameBoard(const QRectF &rect, QWidget *parent)
{
        int i = 0;	
}

void GameBoard::paintEvent(QPaintEvent *)
{
	
}

void GameBoard::paintBlock(QPainter &painter)
{
	painter.setPen(Qt::red);
	QRect rectangle(10, 20, 3, 4);
	painter.drawRect(rectangle);
	
}


void GameBoard::paintBall(QPainter &painter)
{
	painter.setPen(Qt::blue);
	
	
}
