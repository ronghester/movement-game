#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include <QDebug>
#include "gameboard.hpp"

int
main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget *window = new QWidget();
	QVBoxLayout *layout = new QVBoxLayout();
	
	QPushButton *button = new QPushButton("Quit");
	button->connect(button, SIGNAL(clicked()), qApp, SLOT(quit()));
	
	GameBoard *game = new GameBoard();
	
	layout->addWidget(button);
	layout->addWidget(game);
	
	window->setLayout(layout);
	
	window->show();
	
	return app.exec();
}
