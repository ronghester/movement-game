/****************************************************************************
** Meta object code from reading C++ file 'menuSessions.h'
**
** Created: Thu Nov 19 15:11:48 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../menuSessions.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menuSessions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_menuSessions[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_menuSessions[] = {
    "menuSessions\0\0gestionSession()\0"
};

const QMetaObject menuSessions::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_menuSessions,
      qt_meta_data_menuSessions, 0 }
};

const QMetaObject *menuSessions::metaObject() const
{
    return &staticMetaObject;
}

void *menuSessions::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_menuSessions))
        return static_cast<void*>(const_cast< menuSessions*>(this));
    return QWidget::qt_metacast(_clname);
}

int menuSessions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: gestionSession(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
