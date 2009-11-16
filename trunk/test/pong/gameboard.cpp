#include <QRect>
#include <QPainter>
#include "gameboard.hpp"

GameBoard::GameBoard(QWidget *parent)
	:QWidget(parent)
{
	setFixedSize(600, 300);
	setPalette(QColor(255, 255, 130));
	setAutoFillBackground(true);
}

void GameBoard::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	paintBlock(painter);
	paintBall(painter);
	
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
	painter.drawEllipse(QPoint(rect().width()/2, 
				   rect().height()/2)
			    ,20, 20);
	
}
