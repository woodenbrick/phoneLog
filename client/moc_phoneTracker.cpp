/****************************************************************************
** Meta object code from reading C++ file 'phoneTracker.h'
**
** Created: Wed Mar 10 19:02:46 2010
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "phoneTracker.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'phoneTracker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PhoneTracker[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      35,   13,   13,   13, 0x08,
      59,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PhoneTracker[] = {
    "PhoneTracker\0\0on_addCall_clicked()\0"
    "on_number_textChanged()\0on_callMade_toggled()\0"
};

const QMetaObject PhoneTracker::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PhoneTracker,
      qt_meta_data_PhoneTracker, 0 }
};

const QMetaObject *PhoneTracker::metaObject() const
{
    return &staticMetaObject;
}

void *PhoneTracker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PhoneTracker))
        return static_cast<void*>(const_cast< PhoneTracker*>(this));
    if (!strcmp(_clname, "Ui::PhoneWindow"))
        return static_cast< Ui::PhoneWindow*>(const_cast< PhoneTracker*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PhoneTracker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_addCall_clicked(); break;
        case 1: on_number_textChanged(); break;
        case 2: on_callMade_toggled(); break;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
