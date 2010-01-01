#include <QApplication>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "pong.hpp"

int
main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget *main = new QWidget();
	
	QGraphicsScene *scn = new Pong();
	QGraphicsView *view = new QGraphicsView(scn, main);

	main->resize(scn->width(), scn->height());
	main->show();
	return app.exec();
}
