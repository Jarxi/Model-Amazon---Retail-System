/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "main_window.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   17,   12,   11, 0x08,
      50,   11,   11,   11, 0x08,
      65,   63,   11,   11, 0x08,
     116,  111,   86,   11, 0x08,
     138,   11,   11,   11, 0x08,
     168,  154,   11,   11, 0x08,
     199,   11,   11,   11, 0x08,
     218,   11,   11,   11, 0x08,
     234,   11,   11,   11, 0x08,
     251,   11,   11,   11, 0x08,
     271,  154,   11,   11, 0x08,
     320,  312,  306,   11, 0x08,
     351,   11,   11,   11, 0x08,
     362,   11,   11,   11, 0x08,
     374,   11,   11,   11, 0x08,
     392,   11,   11,   11, 0x08,
     418,  413,   11,   11, 0x08,
     448,   11,   11,   11, 0x08,
     483,  468,   11,   11, 0x08,
     527,  519,   11,   11, 0x08,
     554,  545,   11,   11, 0x08,
     573,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0bool\0inputName\0"
    "checkUser(std::string)\0chooseUser()\0"
    "n\0chooseFromCombo(int)\0std::vector<std::string>\0"
    "line\0convToString(QString)\0searchProduct()\0"
    "productHolder\0addList(std::vector<Product*>)\0"
    "saveFileFunction()\0byRateClicked()\0"
    "byAlphaClicked()\0addToCartFunction()\0"
    "addCartList(std::vector<Product*>)\0"
    "User*\0Userstr\0convUserstrToUser(std::string)\0"
    "viewCart()\0closeCart()\0buyCartFunction()\0"
    "removeCartFunction()\0item\0"
    "prodClicked(QListWidgetItem*)\0"
    "addReviewFunction()\0mainReviewList\0"
    "addReviewList(std::vector<Review*>)\0"
    "theYear\0yearSelected(int)\0theMonth\0"
    "monthSelected(int)\0submitFunction()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->checkUser((*reinterpret_cast< std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: _t->chooseUser(); break;
        case 2: _t->chooseFromCombo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { std::vector<std::string> _r = _t->convToString((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::vector<std::string>*>(_a[0]) = _r; }  break;
        case 4: _t->searchProduct(); break;
        case 5: _t->addList((*reinterpret_cast< std::vector<Product*>(*)>(_a[1]))); break;
        case 6: _t->saveFileFunction(); break;
        case 7: _t->byRateClicked(); break;
        case 8: _t->byAlphaClicked(); break;
        case 9: _t->addToCartFunction(); break;
        case 10: _t->addCartList((*reinterpret_cast< std::vector<Product*>(*)>(_a[1]))); break;
        case 11: { User* _r = _t->convUserstrToUser((*reinterpret_cast< std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< User**>(_a[0]) = _r; }  break;
        case 12: _t->viewCart(); break;
        case 13: _t->closeCart(); break;
        case 14: _t->buyCartFunction(); break;
        case 15: _t->removeCartFunction(); break;
        case 16: _t->prodClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 17: _t->addReviewFunction(); break;
        case 18: _t->addReviewList((*reinterpret_cast< std::vector<Review*>(*)>(_a[1]))); break;
        case 19: _t->yearSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->monthSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->submitFunction(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
