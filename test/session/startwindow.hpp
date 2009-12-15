#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class StartWindow : public QWidget
{
Q_OBJECT
public:
	StartWindow(QWidget *parent = 0);
private:
	QPushButton *create;
	QPushButton *select;
	QPushButton *quit;
	QVBoxLayout *vbox;
public slots:
	void new_user_profile();
};

#endif
