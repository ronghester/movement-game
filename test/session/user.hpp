#ifndef USER_H
#define USER_H

#include <QString>
#include <QSettings>

class User
{
public:
	User(QString name);

	void set_games(int i);
	void set_playtime(int i);
	void set_level_score(int category, int i);
	
	QString get_name();
	int get_property(QString property);
private:
	QSettings *config;
};

#endif
