#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "gameboard.hpp"
#include "ball.hpp"

int
main(int argc, char *argv[])
{
  	QApplication app(argc, argv);
	QWidget *window = new QWidget();
	QVBoxLayout *layout = new QVBoxLayout();
// TODO: changer les wigets...	
	QPushButton *button = new QPushButton("Quit");
	button->connect(button, SIGNAL(clicked()), qApp, SLOT(quit()));
	window->setLayout(layout);
	
	window->show();
	
	return app.exec();
}
