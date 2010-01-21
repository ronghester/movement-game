#include "testplugin.hpp"

QString
TestPlugin::plugin_info() 
{
	return "This is the test plugin";
}

Q_EXPORT_PLUGIN2(sg_testplugin, TestPlugin)
