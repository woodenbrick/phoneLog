#include <QtGui>
#include "phoneTracker.h"

PhoneTracker::PhoneTracker(QWidget* parent) : QMainWindow(parent)
{
    setupUi(this);
    QRegExp re("[0-9]{5-30}");
    number->setValidator(new QRegExpValidator(re, this));
    model =  new QStandardItemModel();
    callList->setModel(model);
    callList->setColumnWidth(0, 50);
    callList->setColumnWidth(1, 50);
    QHeaderView* headers = new QHeaderView(Qt::Horizontal, model);
    model->setHorizontalHeaderItem(0, new QStandardItem("Date"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Phone number"));
    model->setHorizontalHeaderLabels(QStringList("Test"));
    QDateTime currentTime = QDateTime();
    currentTime.currentDateTime();
    dateEdit->setDateTime(currentTime);
    readServer();
    callList->setHorizontalHeader(new QHeaderView());
    //timeEdit->time().setTime(currentTime.time());
}

void PhoneTracker::readServer()
{
    QFile xml("../xmltest");
    xml.open(QIODevice::ReadOnly | QIODevice::Text);
    QList<QStandardItem*> record;
    QXmlStreamReader doc(&xml);
    model->clear();
    while(doc.readNext() && !doc.atEnd())
    {
        if(doc.name() == "record" && doc.tokenType() == QXmlStreamReader::StartElement)
        {
            doc.readNext();
            while(doc.readNext() && !doc.atEnd())
            {
                if(doc.name() != "record" && doc.tokenType() != QXmlStreamReader::EndElement)
                {
                    if(doc.name() == "number")
                        record.append(new QStandardItem(doc.readElementText()));
                    if(doc.name() == "date")
                    {
                        QDateTime t;
                        QString s(doc.readElementText());
                        qDebug() << s;
                        t.fromString(s, Qt::ISODate);
                        qDebug() << "Date" << t.date().toString();
                        record.prepend(new QStandardItem(t.toString()));
                        break;
                    }
                }
            }
            model->appendRow(record);
            record.clear();
        }
    }

}

void PhoneTracker::on_addCall_clicked()
{
    QList<QStandardItem*> list;
    QString timeString;
    if(callMade->isChecked())
    {
        QDateTime* time = new QDateTime();
        timeString = time->currentDateTime().toString();
    }
    else
        dateEdit->setTime(timeEdit->time());
        timeString = dateEdit->dateTime().toString(Qt::ISODate);
    list.append(new QStandardItem(number->text()));
    list.append(new QStandardItem(timeString));
    model->appendRow(list);
    number->clear();
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
