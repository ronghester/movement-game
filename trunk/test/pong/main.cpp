#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPushButton>
#include <QMenuBar>
int
main(int argc, char *argv[])
{
	QApplication *app = new QApplication(argc, argv);
	QWidget *window = new QWidget();
	window->setWindowTitle("Serious Game");
	window->setFixedSize(640, 480);
	
	QPushButton *button = new QPushButton("Quit");
	button->connect(button, SIGNAL(clicked()), app, SLOT(quit()));
	
	QVBoxLayout *layout = new QVBoxLayout(window);
	layout->addWidget(button);
	
	QGraphicsScene *scene = new QGraphicsScene();
	QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem("This is it");
	scene->addItem(text);
	//text->setPos(10, 10);
	QGraphicsRectItem *rect = new QGraphicsRectItem(-500, -10,20, 100);
	rect->setBrush(QBrush(Qt::red));
	
	scene->addItem(rect);
	
	
	QGraphicsView *view = new QGraphicsView(scene, window);
	view->setRenderHints(QPainter::Antialiasing);
	layout->addWidget(view);
	
	window->show();
	
	return app->exec();
}
