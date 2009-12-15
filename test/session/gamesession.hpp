#ifndef GAMESESSION_H
#define GAMESESSION_H

#include <QWidget>
#include "startwindow.hpp"

class GameSession : public QObject
{
public:
	GameSession();
	void launch();
private:
	StartWindow *start;
};

#endif
