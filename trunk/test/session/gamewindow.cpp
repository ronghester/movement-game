#include "gamewindow.hpp"

GameWindow::GameWindow(QGraphicsScene *scene, QWidget *parent)
	:QWidget(parent)
{
	view = new QGraphicsView(scene, this);
	quit = new QPushButton(tr("Quit"));

	layout = new QVBoxLayout(this);
	layout->addWidget(quit);
	layout->addWidget(view);

	this->setWindowTitle(tr("Let's play !"));
}
