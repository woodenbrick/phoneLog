#ifndef PHONETRACKER_H
#define PHONETRACKER_H

#include <QtGui>
#include <QtNetwork>
#include "ui_phone.h"

class PhoneTracker : public QMainWindow, public Ui::PhoneWindow
{
Q_OBJECT;
private:
    QUrl addUrl;
    QUrl retrieveUrl;
    QNetworkAccessManager conn;
    QNetworkRequest request;
    QStandardItemModel* model;
    QString group;
    QString caller;
    void parseRecord(QXmlStreamReader& doc);
    void writeServer(QDateTime& date);
public:
    PhoneTracker(QWidget* parent=0);
    void readServer();

private slots:
    void on_addCall_clicked();
    void on_number_textChanged();
    void on_callMade_toggled();
    void requestFinishedCB(QNetworkReply* reply);
};

#endif // PHONETRACKER_H
