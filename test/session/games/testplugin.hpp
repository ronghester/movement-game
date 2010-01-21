#ifndef TESTPLUGIN_H
#define TESTPLUGIN_H

#include <QObject>
#include "gameinterface.hpp"

class TestPlugin : public QObject, public GameInterface 
{
Q_OBJECT
Q_INTERFACES(GameInterface)
	public:
	QString plugin_info();
};


#endif
