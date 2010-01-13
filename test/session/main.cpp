#include <QTranslator>
#include <QApplication>

#include "gamesession.hpp"

int
main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QTranslator translator;
	translator.load("sg_fr", "lang");
	app.installTranslator(&translator);

	GameSession *session = new GameSession();
	session->launch();
	return app.exec();
}

