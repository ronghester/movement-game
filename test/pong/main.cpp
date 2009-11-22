#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QMenuBar>
int
main(int argc, char *argv[])
{
	QApplication *app = new QApplication(argc, argv);
	QWidget *window = new QWidget();
	window->setWindowTitle("Test");
	window->setFixedSize(640, 480);
	
	QPushButton *button = new QPushButton("Quit");
	button->connect(button, SIGNAL(clicked()), app, SLOT(quit()));
	
	QVBoxLayout *layout = new QVBoxLayout(window);
	layout->addWidget(button);
	
	QGraphicsScene *scene = new QGraphicsScene();
	scene->addText("This is it");
	
	QGraphicsView *view = new QGraphicsView(scene, window);
	layout->addWidget(view);
	
	window->show();
	
	return app->exec();
}
