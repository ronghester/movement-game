#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QVBoxLayout>

class GameWindow : public QWidget
{
Q_OBJECT
public:
	GameWindow(QGraphicsScene *scene, QWidget *parent = 0);
private:
	QGraphicsView *view;
	QPushButton *quit;
	QVBoxLayout *layout;
};

#endif
