#include "databasehandler.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QVariantMap>
#include "homepage.h"
DatabaseHandler::DatabaseHandler(QObject *parent)
    : QObject(parent)
{
    this->networkManager = new QNetworkAccessManager(this);
    connect(this,SIGNAL(sendRes(QString)),parent,SLOT(receiveRes(QString)));
}

DatabaseHandler::~DatabaseHandler()
{
  networkManager->deleteLater();
}

void DatabaseHandler::networkReplyReadyRead()
{
        char *before = "\"";
        char *after = "";
        QString re = networkReply->readAll().replace(before,after);

        //qDebug() << networkReply->readAll()[0];
        emit sendRes(re);
}

void DatabaseHandler::getAll(){
    QString qurl = QString::fromStdString(url+"test.json");
    this->networkReply = networkManager->
            get(QNetworkRequest(QUrl(qurl)));

    connect(networkReply,&QNetworkReply::readyRead,this,&DatabaseHandler::networkReplyReadyRead);
}

void DatabaseHandler::addOne(DataStruct data){
    QVariantMap newOne;
    QList<QString> keys = data.getKeys();
    for(int i=0;i<keys.size();i++){
        newOne[keys[i]] = data.getValue(keys[i]);
    }
    QJsonDocument jsonDoc = QJsonDocument::fromVariant(newOne);
    QNetworkRequest req(QUrl(QString::fromStdString(url+"test.json")));
    req.setHeader(QNetworkRequest::ContentTypeHeader,QString("application/json"));
    qDebug() << jsonDoc;
    networkManager->post(req,jsonDoc.toJson());

}
