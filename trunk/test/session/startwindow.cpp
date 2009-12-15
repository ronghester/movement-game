#include <QApplication>
#include <QDesktopWidget>
#include <QDir>
#include <QInputDialog>
#include <QDebug>

#include "userwindow.hpp"
#include "startwindow.hpp"

StartWindow::StartWindow(QWidget *parent) 
	:QWidget(parent)
{
	this->setWindowTitle("Serious Game");

	create = new QPushButton("Create profile");
	select = new QPushButton("Select profile");
	quit = new QPushButton("Quit");

	// layout
	vbox = new QVBoxLayout(this);
	vbox->addWidget(create);
	vbox->addWidget(select);
	vbox->addWidget(quit);

	// signals connection
	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	connect(create, SIGNAL(clicked()), this, SLOT(new_user_profile()));
	connect(select, SIGNAL(clicked()), this, SLOT(list_users()));
	this->show();
}

void 
StartWindow::new_user_profile()
{
	this->hide();
	bool response;
	QString username = QInputDialog::getText(0, "New profile",
					     "Please enter a name : ", 
					     QLineEdit::Normal,
		  			     "Votre nom", &response); 
	if (response) {
		emit(send_user(username));
	} else {
		this->show();
	}
	// TODO : record_new_user(username);
}

void 
StartWindow::list_users()
{
	this->hide();
	QDir *cur = new QDir();
	bool ok;
	QString username = QInputDialog::getItem(0, 
				     "Profile selection",
				     "Please pick a profile",
				     cur->entryList(),
				     0,
				     false,
				     &ok);	

	if(ok) {
		emit(send_user(username));
	} else {
		this->show();
	}
}
