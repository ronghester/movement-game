#include <QApplication>
#include "menuSessions.h"
#include "utilisateur.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    menuSessions Menu;

    return app.exec();
}
