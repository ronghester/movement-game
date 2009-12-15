#include <QApplication>
#include "userscreen.hpp"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	Userscreen menu("baptiste");
	menu.show();
	
	return app.exec();
	return 0;
}
