#include <QApplication>
#include "MenuSessions.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    MenuSessions menu;

    return app.exec();
}
