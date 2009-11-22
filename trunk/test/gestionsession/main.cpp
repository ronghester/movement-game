#include <QApplication>
#include "menusessions.hpp"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    MenuSessions menu;

    return app.exec();
}
