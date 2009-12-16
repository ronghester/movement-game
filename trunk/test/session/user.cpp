#include "user.hpp"

// TODO : find a smart way to remove toInt() (i.e learn QVariant)

User::User(QString name)
{
	// QSettings(path, format)
	config = new QSettings("users/"+name, QSettings::NativeFormat);

	// checking if file !exists by testing property "name"
	if (!config->contains("name")) {
		config->setValue("name", name);
		config->setValue("games", 0);
		config->setValue("playtime", 0);
		
		config->setValue("category1", 0);
		config->setValue("category2", 0);
		config->setValue("category3", 0);
		config->setValue("category4", 0);
	}
}

void
User::set_games(int i)
{
	int previous = config->value("games").toInt();
	config->setValue("games", i+previous);
}

void 
User::set_playtime(int i)
{
	int previous = config->value("playtime").toInt();
	config->setValue("playtime", i+previous);
}

void
User::set_level_score(int category, int i)
{
	QString cat = "category" + category;
	int previous = config->value(cat).toInt();
	config->setValue(cat, i+previous);
}

int
User::get_property(const QString property)
{
	return config->value(property).toInt();
}

QString
User::get_name()
{
	return config->value("name").toString();
}
