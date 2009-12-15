#include <QApplication>

#include "gamesession.hpp"

int
main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	GameSession *session = new GameSession();
	session->launch();
	return app.exec();
}

