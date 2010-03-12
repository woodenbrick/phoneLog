/********************************************************************************
** Form generated from reading ui file 'phone.ui'
**
** Created: Wed Mar 10 18:55:48 2010
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PHONE_H
#define UI_PHONE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDateEdit>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTimeEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhoneWindow
{
public:
    QWidget *centralwidget;
    QTableView *callList;
    QPushButton *addCall;
    QLineEdit *number;
    QCheckBox *callMade;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PhoneWindow)
    {
    if (PhoneWindow->objectName().isEmpty())
        PhoneWindow->setObjectName(QString::fromUtf8("PhoneWindow"));
    PhoneWindow->resize(800, 600);
    centralwidget = new QWidget(PhoneWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    callList = new QTableView(centralwidget);
    callList->setObjectName(QString::fromUtf8("callList"));
    callList->setGeometry(QRect(70, 30, 491, 271));
    addCall = new QPushButton(centralwidget);
    addCall->setObjectName(QString::fromUtf8("addCall"));
    addCall->setEnabled(false);
    addCall->setGeometry(QRect(400, 370, 80, 28));
    number = new QLineEdit(centralwidget);
    number->setObjectName(QString::fromUtf8("number"));
    number->setGeometry(QRect(130, 370, 251, 31));
    callMade = new QCheckBox(centralwidget);
    callMade->setObjectName(QString::fromUtf8("callMade"));
    callMade->setGeometry(QRect(130, 420, 201, 24));
    callMade->setChecked(true);
    timeEdit = new QTimeEdit(centralwidget);
    timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
    timeEdit->setEnabled(false);
    timeEdit->setGeometry(QRect(260, 450, 118, 28));
    timeEdit->setCalendarPopup(true);
    dateEdit = new QDateEdit(centralwidget);
    dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
    dateEdit->setEnabled(false);
    dateEdit->setGeometry(QRect(130, 450, 110, 28));
    dateEdit->setMaximumDateTime(QDateTime(QDate(7999, 11, 30), QTime(23, 59, 59)));
    dateEdit->setCalendarPopup(true);
    PhoneWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(PhoneWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 26));
    PhoneWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(PhoneWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    PhoneWindow->setStatusBar(statusbar);

    retranslateUi(PhoneWindow);

    QMetaObject::connectSlotsByName(PhoneWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PhoneWindow)
    {
    PhoneWindow->setWindowTitle(QApplication::translate("PhoneWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    addCall->setText(QApplication::translate("PhoneWindow", "Add New", 0, QApplication::UnicodeUTF8));
    callMade->setText(QApplication::translate("PhoneWindow", "Call made at current time", 0, QApplication::UnicodeUTF8));
    dateEdit->setDisplayFormat(QApplication::translate("PhoneWindow", "d MMM yyyy", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(PhoneWindow);
    } // retranslateUi

};

namespace Ui {
    class PhoneWindow: public Ui_PhoneWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHONE_H
