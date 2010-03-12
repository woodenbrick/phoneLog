#ifndef PHONETRACKER_H
#define PHONETRACKER_H

#include <QtGui>
#include "ui_phone.h"

class PhoneTracker : public QMainWindow, public Ui::PhoneWindow
{
Q_OBJECT;
private:
    QStandardItemModel* model;
public:
    PhoneTracker(QWidget* parent=0);
    void readServer();

private slots:
    void on_addCall_clicked();
    void on_number_textChanged();
    void on_callMade_toggled();
};

#endif // PHONETRACKER_H
