#include <QApplication>
#include <QDesktopWidget>
#include <QInputDialog>
#include <QDebug>

#include "startwindow.hpp"

StartWindow::StartWindow(QWidget *parent) 
	:QWidget(parent)
{
	// Geometry
	// getting screen size and adapting window to it
	int windowWidth = qApp->desktop()->width();
	int windowHeight = qApp->desktop()->height();
	
	// setting 4/3 ratio
	this->setFixedSize(windowWidth/4,
			   windowHeight/6);
	int centerx = windowWidth - this->width();
	int centery = windowHeight - this->height();
	
	// and finally centering the window
	this->move(centerx/2, centery/2);

	this->setWindowTitle("Serious Game");

	create = new QPushButton("Create profile");
	select = new QPushButton("Select profile");
	quit = new QPushButton("Quit");

	vbox = new QVBoxLayout(this);

	vbox->addWidget(create);
	vbox->addWidget(select);
	vbox->addWidget(quit);

	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	connect(create, SIGNAL(clicked()), this, SLOT(new_user_profile()));
	this->show();
}

void 
StartWindow::new_user_profile()
{
	bool ok;
	QString username = QInputDialog::getText(0, "New profile",
					     "Please enter a name : ", 
					     QLineEdit::Normal,
		  			     "Votre nom", &ok); 
	if (ok) {
		qDebug()<<"We've got a new user !";
	}
}
