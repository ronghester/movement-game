#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include <QtPlugin>
#include <QString>

class GameInterface 
{
public:
	virtual ~GameInterface() {};
	virtual QString plugin_info() = 0;
};

Q_DECLARE_INTERFACE(GameInterface, 
		    "org.mojos.seriousgame.GameInterface/0.1");


#endif
