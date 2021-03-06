#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H
//#include "homepage.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <String>

struct DataStruct{
    QString id;
    QString title;
    QString description;
    QString type;
    QDate created;
    QDate deadline;
    QString sort;
    int percent;

    static QList<QString> getKeys(){
        QList<QString> list = {"created","deadline","description","percent","title","type"};

        return list;
    }

    void setValue(QString _id,QString _deadline,QString _description,QString _percent,QString _title,QString _type,QString _created){
        title = _title;
        description = _description;
        type = _type;
        id = _id;
        percent = _percent.toInt();


        QList<QString> l = _deadline.split(".");
        if (l.size()==3)
            deadline = QDate(l[2].toInt(),l[1].toInt(),l[0].toInt());
        l = _created.split(".");
        if (l.size()==3)
            created = QDate(l[0].toInt(),l[1].toInt(),l[0].toInt());

    }

    void setValue(QString _id,QString _deadline,QString _description,QString _type,QString _title,QString _percent){
        title = _title;
        description = _description;
        type = _type;
        id = _id;
        percent = _percent.toInt();

        QList<QString> l = _deadline.split(".");
        if (l.size()==3)
            deadline = QDate(l[2].toInt(),l[1].toInt(),l[1].toInt());
        created = QDate::currentDate();
    }

    QString getValue(QString key){
        if (QString::compare(key,"id")==0) return id;
        if (QString::compare(key,"title")==0) return title;
        if (QString::compare(key,"description")==0) return description;
        if (QString::compare(key,"type")==0) return type;
        if (QString::compare(key,"created")==0) return created.toString("dd.MM.yyyy");
        if (QString::compare(key,"deadline")==0) return deadline.toString("dd.MM.yyyy");
        if (QString::compare(key,"percent")==0) return QString::number(percent);
    }

    bool operator<(const DataStruct& a) const
       {
        if (sort=="Progress")
           return percent < a.percent;
        else if (sort=="Name")
             return title < a.title;
        else // (sort=="Deadline")
             return deadline < a.deadline;
       }
};

class DatabaseHandler : public QObject
{
        Q_OBJECT
public:
    DatabaseHandler(QObject *parent = nullptr);
    ~DatabaseHandler();
    void getAll();
    void addOne(DataStruct data);
    void deleteOne(DataStruct data);
    void updateOne(DataStruct data);

 public slots:

    void networkReplyReadyRead();
 signals:
    void sendRes(QString res);
private :
    QString url = "https://newme-ed0c4-default-rtdb.asia-southeast1.firebasedatabase.app/";
    QNetworkAccessManager *networkManager ;
    QNetworkReply *networkReply;
    QList<QString> types;
};

#endif // DATABASEHANDLER_H
