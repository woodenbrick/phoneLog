#include <QtGui>
#include "phoneTracker.h"

PhoneTracker::PhoneTracker(QWidget* parent) : QMainWindow(parent)
{
    group = "tard";
    caller = "Daniel";
    setupUi(this);
    QRegExp re("[0-9 ]+");
    number->setValidator(new QRegExpValidator(re, this));
    model =  new QStandardItemModel();
    callList->setModel(model);
    callList->setSelectionBehavior(QAbstractItemView::SelectRows);
    callList->verticalHeader()->hide();
    callList->horizontalHeader()->hide();
    addUrl = "http://phonenumbertracker.appspot.com/add";
    retrieveUrl = QString("http://phonenumbertracker.appspot.com/retrieve/%1").arg(group);
    connect(&conn, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinishedCB(QNetworkReply*)));
    QDateTime currentTime = QDateTime::currentDateTime();
    dateEdit->setDateTime(currentTime);
    timeEdit->setDateTime(currentTime);
    number->setFocus(Qt::OtherFocusReason);
    readServer();
}

void PhoneTracker::readServer()
{
    model->clear();
    model->appendRow(new QStandardItem("Downloading records..."));
    request.setUrl(retrieveUrl);
    conn.get(request);
}

void PhoneTracker::requestFinishedCB(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError)
    {
        qDebug() << reply->errorString();
    }
    if (reply->request().url().toString() == retrieveUrl.toString())
    {
        QXmlStreamReader doc(reply);
        model->clear();
        while(doc.readNext() && !doc.atEnd())
        {
            if(doc.name() == "record" && doc.tokenType() == QXmlStreamReader::StartElement)
                parseRecord(doc);
        }
    }
    callList->setColumnWidth(1, 250);
    callList->setColumnWidth(2, 100);
    callList->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);

}

void PhoneTracker::parseRecord(QXmlStreamReader& doc)
{
    QList<QStandardItem*> record;
    doc.readNext();
    while(doc.name() != "record" && doc.tokenType() != QXmlStreamReader::EndElement)
    {
        if(doc.name() == "date")
        {
            QDateTime t = QDateTime::fromString(doc.readElementText(), Qt::ISODate);
            record.append(new QStandardItem(t.toString()));
        }
        if(doc.name() == "number")
            record.append(new QStandardItem(doc.readElementText()));
        if(doc.name() == "caller")
            record.append(new QStandardItem(doc.readElementText()));
        doc.readNext();
    }
    model->appendRow(record);
    record.clear();
}


void PhoneTracker::on_addCall_clicked()
{
    QList<QStandardItem*> list;
    QDateTime time;
    if(callMade->isChecked())
        time = QDateTime::currentDateTime();
    else
    {
        dateEdit->setTime(timeEdit->time());
        time = dateEdit->dateTime();
    }
    list.append(new QStandardItem(time.toString()));
    list.append(new QStandardItem(number->text()));
    list.append(new QStandardItem(caller));
    model->appendRow(list);
    writeServer(time);
    number->clear();
}


void PhoneTracker::writeServer(QDateTime& date)
{
    QString postData = QString("number=%1&group=%2&user=%3&date=%4").arg(
            number->text(), group, caller, date.toString(Qt::ISODate));
    QByteArray data(postData.toAscii());
    request.setUrl(addUrl);
    conn.post(request, data);
}



void PhoneTracker::on_number_textChanged()
{
    addCall->setEnabled(number->hasAcceptableInput());
}

void PhoneTracker::on_callMade_toggled()
{
    dateEdit->setEnabled(!callMade->isChecked());
    timeEdit->setEnabled(!callMade->isChecked());
}

int main(int argc, char* argv[])
{
    QApplication* app = new QApplication(argc, argv);
    PhoneTracker* tracker = new PhoneTracker();
    tracker->show();
    return app->exec();
}
