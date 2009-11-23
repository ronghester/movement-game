#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>

#include "player.hpp"

int
main(int argc, char *argv[])
{
	QApplication *app = new QApplication(argc, argv);
	QWidget *window = new QWidget();
	window->setWindowTitle("Serious Game");
	window->setFixedSize(640, 480);
	
	// Bouton d'arrêt
	QPushButton *button = new QPushButton("Quit");
	button->connect(button, SIGNAL(clicked()), app, SLOT(quit()));
	
	QVBoxLayout *layout = new QVBoxLayout(window);
	layout->addWidget(button);
	
	// Canvas utilisé pour le jeu
	QGraphicsScene *scene = new QGraphicsScene();

	// Un nouveau joueur Pong, i.e un rectangle
	Player *p1 = new Player(-500, 0, 20, 100, QBrush(Qt::red));
	Player *p2 = new Player(scene->width()-50, 0, 20, 100, QBrush(Qt::blue));
	
      	scene->addItem(p1);
	scene->addItem(p2);
	
		
	// Notre vue sur la scène
	QGraphicsView *view = new QGraphicsView(scene, window);
	
	layout->addWidget(view);
	
	window->show();
	
	return app->exec();
}
