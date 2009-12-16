#include <QApplication>
#include <QDesktopWidget>

#include "gamesession.hpp"

GameSession::GameSession() 
{
	start = new StartWindow();

	center_widget(start);
	
	connect(start, 
		SIGNAL(send_user(QString)),
		this, 
		SLOT(show_user(QString)));
}

void
GameSession::center_widget(QWidget *widget) 
{
	// getting screen size
	int windowWidth = qApp->desktop()->width();
	int windowHeight = qApp->desktop()->height();
	
	// setting size and position
	//widget->setFixedSize(windowWidth/4, windowHeight/6);
	int centerx = windowWidth - widget->width();
	int centery = windowHeight - widget->height();
	widget->move(centerx/2, centery/2);
}

void 
GameSession::launch() 
{
	start->show();
}

void 
GameSession::show_user(QString username)
{
	this->start->hide();

	user = new User(username);
	userwindow = new UserWindow(user);
	center_widget(userwindow);	
	userwindow->show();
}
