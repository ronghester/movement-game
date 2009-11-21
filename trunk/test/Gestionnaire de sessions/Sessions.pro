TEMPLATE  = app
HEADERS   = menuSessions.h \
	    utilisateur.h \
	    menuUtilisateur.h
SOURCES   = menuSessions.cpp \
	    utilisateur.cpp \
	    menuUtilisateur.cpp \
            main.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]
INSTALLS += target sources
