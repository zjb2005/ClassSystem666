/****************************************************************************
** Meta object code from reading C++ file 'classset.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../classset.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'classset.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN8ClassSetE_t {};
} // unnamed namespace

template <> constexpr inline auto ClassSet::qt_create_metaobjectdata<qt_meta_tag_ZN8ClassSetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ClassSet",
        "sendData",
        "",
        "ClassData",
        "data",
        "sendPrinterData",
        "QList<Classes>",
        "classesResultLists",
        "on_beginButton_clicked",
        "on_pushB1_clicked",
        "on_clearButton_clicked",
        "on_printerClassesResultButton_clicked",
        "on_searchButton_clicked",
        "on_classSettingbtn_clicked",
        "on_deleteBtn_clicked",
        "updateCheckBoxStates",
        "receiveClassesResultData"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'sendData'
        QtMocHelpers::SignalData<void(ClassData)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'sendPrinterData'
        QtMocHelpers::SignalData<void(QList<Classes>)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Slot 'on_beginButton_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_pushB1_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_clearButton_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_printerClassesResultButton_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_searchButton_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_classSettingbtn_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_deleteBtn_clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'updateCheckBoxStates'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'receiveClassesResultData'
        QtMocHelpers::SlotData<void(QList<Classes>)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ClassSet, qt_meta_tag_ZN8ClassSetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ClassSet::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8ClassSetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8ClassSetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8ClassSetE_t>.metaTypes,
    nullptr
} };

void ClassSet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ClassSet *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< std::add_pointer_t<ClassData>>(_a[1]))); break;
        case 1: _t->sendPrinterData((*reinterpret_cast< std::add_pointer_t<QList<Classes>>>(_a[1]))); break;
        case 2: _t->on_beginButton_clicked(); break;
        case 3: _t->on_pushB1_clicked(); break;
        case 4: _t->on_clearButton_clicked(); break;
        case 5: _t->on_printerClassesResultButton_clicked(); break;
        case 6: _t->on_searchButton_clicked(); break;
        case 7: _t->on_classSettingbtn_clicked(); break;
        case 8: _t->on_deleteBtn_clicked(); break;
        case 9: _t->updateCheckBoxStates(); break;
        case 10: _t->receiveClassesResultData((*reinterpret_cast< std::add_pointer_t<QList<Classes>>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ClassSet::*)(ClassData )>(_a, &ClassSet::sendData, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClassSet::*)(QList<Classes> )>(_a, &ClassSet::sendPrinterData, 1))
            return;
    }
}

const QMetaObject *ClassSet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClassSet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8ClassSetE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ClassSet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void ClassSet::sendData(ClassData _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void ClassSet::sendPrinterData(QList<Classes> _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP
