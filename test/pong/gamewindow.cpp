#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QVBoxLayout>
#include <QPushButton>

#include "gamewindow.hpp"
GameWindow::GameWindow(QWidget *parent)
	:QWidget(parent)
{
	// getting screen size and adapting window to it
	int windowWidth = qApp->desktop()->width();
	int windowHeight = qApp->desktop()->height();
	
	// setting 4/3 ratio
	this->setFixedSize(windowWidth-windowWidth/4,
			   windowHeight-windowHeight/3);
	int centerx = windowWidth - this->width();
	int centery = windowHeight - this->height();
	
	// and finally centering the window
	this->move(centerx/2, centery/2);
	this->setWindowTitle("Serious Game");
		
	this->layout = new QVBoxLayout(this);
	
	this->quitbutton = new QPushButton("Quit");
	this->session = new GameSession();// aka QGraphicsScene
	this->view = new QGraphicsView(session);

	// signals
	connect(quitbutton, SIGNAL(clicked()), qApp , SLOT(quit()));
	
	// build the window     
	this->layout->addWidget(quitbutton);
	this->layout->addWidget(view);
	
}
