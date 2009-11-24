#include <QApplication>
#include <QDebug>

#include "gamewindow.hpp"

int
main(int argc, char *argv[])
{
	QApplication *app = new QApplication(argc, argv);
	GameWindow *window = new GameWindow();
	window->show();
	return app->exec();
}


