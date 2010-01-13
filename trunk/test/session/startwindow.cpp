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

	create = new QPushButton(tr("Create profile"));
	select = new QPushButton(tr("Select profile"));
	quit = new QPushButton(tr("Quit"));

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
	QString username = QInputDialog::getText(0, tr("New profile"),
						 tr("Please enter a name : "), 
						 QLineEdit::Normal,
						 tr("Your name"), &response); 
	if (response) {
		emit(send_user(username));
	} else {
		this->show();
	}
}

void 
StartWindow::list_users()
{
	this->hide();

	// we're going to look up existing profiles in the users/ directory
	QDir *cur = new QDir(QDir::currentPath()+"/users/");

	// shows only files
	cur->setFilter(QDir::Files);
	bool ok;
	QString username = QInputDialog::getItem(0, 
						 tr("Profile selection"),
						 tr("Please pick a profile"),
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
