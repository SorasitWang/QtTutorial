#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H
//#include "homepage.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <String>

struct DataStruct{
    QString title;
    QString description;
    QString img;
    QDate created;
    QDate deadline;

    QList<QString> getKeys(){
        QList<QString> list = { "title", "description", "img" , "created" , "deadline" };

        return list;
    }

    void setValue(QString _title,QString _description,QString _img,QString _deadline){
        title = _title;
        description = _description;
        img = _img;

        QList<QString> l = _deadline.split(",");
        deadline = QDate(l[0].toInt(),l[1].toInt(),l[2].toInt());
    }

    QString getValue(QString key){
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
