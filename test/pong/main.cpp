#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsEllipseItem>
#include <QDebug>

#include "player.hpp"

int
main(int argc, char *argv[])
{
	QApplication *app = new QApplication(argc, argv);
	QWidget *window = new QWidget();
	window->setWindowTitle("Serious Game");

	QVBoxLayout *layout = new QVBoxLayout(window);

	// quit button
	QPushButton *button = new QPushButton("Quit");
	button->connect(button, SIGNAL(clicked()), app, SLOT(quit()));
		
	// the game scene
	QGraphicsScene *scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, 500, 300);	
	
	// the game view
	QGraphicsView *view = new QGraphicsView(scene, window);

	// the ball
	QGraphicsEllipseItem *balle = new QGraphicsEllipseItem(scene->width()/2-15, scene->height()/2-15, 30, 30);
		
	// two new players = QGraphicsRect.
	Player *p1 = new Player(0, scene->height()/2-50, 20, 100, QBrush(Qt::blue));
	Player *p2 = new Player(scene->width()-20, scene->height()/2-50, 20, 100, QBrush(Qt::red));

	// Adding items to the scene
	scene->addItem(p1);
	scene->addItem(p2);
	scene->addItem(balle);
	
	// Trying to make p1 grab key events
	scene->setFocusItem(p1);
	
	if (scene->focusItem()==p1){
		std::cout<<"I've got the power.";
	}
	
	
	// Adding the button and the view.
	layout->addWidget(button);
	layout->addWidget(view);

	window->show();
	
	return app->exec();
}


