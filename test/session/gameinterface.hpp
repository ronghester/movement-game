#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include <QtPlugin>
#include <QStringList>

class GameInterface 
{
public:
	virtual ~GameInterface() {};

	/* plugin_info() returns a QStringList storing *
	 * informations about the plugin. It's indexed *
	 * like this :
	 * 0 : category
	 * 1 : name
	 * 2 : description
	 * 3 : author
	 * 4 : version
	 */

	virtual QStringList plugin_info() = 0;
};

Q_DECLARE_INTERFACE(GameInterface, 
		    "org.mojos.seriousgame.GameInterface/0.1");


#endif
