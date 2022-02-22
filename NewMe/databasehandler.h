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
    QString img;
    QDate created;
    QDate deadline;

    static QList<QString> getKeys(){
        QList<QString> list = {"id","created","deadline","description","img" ,"title"};

        return list;
    }

    void setValue(QString _id,QString _deadline,QString _description,QString _img,QString _title,QString _created){
        title = _title;
        description = _description;
        img = _img;
        id = _id;

        QList<QString> l = _deadline.split(".");
        deadline = QDate(l[0].toInt(),l[1].toInt(),l[2].toInt());
    }

    void setValue(QString _id,QString _deadline,QString _description,QString _img,QString _title){
        title = _title;
        description = _description;
        img = _img;
        id = _id;

        QList<QString> l = _deadline.split(".");
        deadline = QDate(l[0].toInt(),l[1].toInt(),l[2].toInt());
        created = QDate::currentDate();
    }

    QString getValue(QString key){
        if (QString::compare(key,"id")==0) return id;
        if (QString::compare(key,"title")==0) return title;
        if (QString::compare(key,"description")==0) return description;
        if (QString::compare(key,"img")==0) return img;
        if (QString::compare(key,"created")==0) return created.toString("dd.MM.yyyy");
        if (QString::compare(key,"deadline")==0) return deadline.toString("dd.MM.yyyy");
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
 public slots:

    void networkReplyReadyRead();
 signals:
    void sendRes(QString res);
private :
    std::string url = "https://newme-ed0c4-default-rtdb.asia-southeast1.firebasedatabase.app/";
    QNetworkAccessManager *networkManager ;
    QNetworkReply *networkReply;
};

#endif // DATABASEHANDLER_H
