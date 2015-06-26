/****************************************************************************
** Meta object code from reading C++ file 'issuelist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IssueTracker/issuelist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'issuelist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IssueList_t {
    QByteArrayData data[9];
    char stringdata[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IssueList_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IssueList_t qt_meta_stringdata_IssueList = {
    {
QT_MOC_LITERAL(0, 0, 9), // "IssueList"
QT_MOC_LITERAL(1, 10, 8), // "modified"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 8), // "selected"
QT_MOC_LITERAL(4, 29, 14), // "QItemSelection"
QT_MOC_LITERAL(5, 44, 12), // "newSelection"
QT_MOC_LITERAL(6, 57, 12), // "oldSelection"
QT_MOC_LITERAL(7, 70, 11), // "solve_issue"
QT_MOC_LITERAL(8, 82, 9) // "add_issue"

    },
    "IssueList\0modified\0\0selected\0"
    "QItemSelection\0newSelection\0oldSelection\0"
    "solve_issue\0add_issue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IssueList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   35,    2, 0x0a /* Public */,
       7,    0,   40,    2, 0x0a /* Public */,
       8,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void IssueList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IssueList *_t = static_cast<IssueList *>(_o);
        switch (_id) {
        case 0: _t->modified(); break;
        case 1: _t->selected((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 2: _t->solve_issue(); break;
        case 3: _t->add_issue(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IssueList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IssueList::modified)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject IssueList::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IssueList.data,
      qt_meta_data_IssueList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IssueList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IssueList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IssueList.stringdata))
        return static_cast<void*>(const_cast< IssueList*>(this));
    return QWidget::qt_metacast(_clname);
}

int IssueList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void IssueList::modified()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
