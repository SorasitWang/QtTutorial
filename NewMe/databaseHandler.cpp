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
        //qDebug() << networkReply->readAll();
        QString re = networkReply->readAll().replace(before,after);



        emit sendRes(re);
}

void DatabaseHandler::getAll(){
    char *before = "\"";
    char *after = "";
    QString re = "{\"1\":{\"created\":\"2022.5.3\",\"deadline\":\"2022.10.3\",\"description\":\"for pat1!\",\"type\":\"Money\",\"title\":\"study\",\"percent\":\"55\"},\"-MwQSbfiycW0amw7zHCZ\":{\"created\":\"2022.02.02\",\"deadline\":\"2023.01.01\",\"description\":\"Helloworld\",\"type\":\"Healthy\",\"title\":\"aa\",\"percent\":\"75\"},\"-MwQgJIEAmiMnBbUt6Bt\":{\"created\":\"2022.02.22\",\"deadline\":\"2022.03.03\",\"description\":\"Helloworld\",\"type\":\"Money\",\"title\":\"sos\",\"percent\":\"90\"}}";
    re = re.replace(before,after);
    emit sendRes(re);

    return ;

    QString qurl = QString::fromStdString(url+"test.json");
    networkReply = networkManager->
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
void DatabaseHandler::deleteOne(DataStruct data){
    QNetworkRequest req(QUrl(QString::fromStdString(url+"test.json")));
    req.setHeader(QNetworkRequest::ContentTypeHeader,QString("application/json"));
    networkManager->deleteResource(req);
}

void DatabaseHandler::updateOne(DataStruct data){
    QVariantMap newOne;
    QList<QString> keys = data.getKeys();
    for(int i=0;i<keys.size();i++){
        newOne[keys[i]] = data.getValue(keys[i]);
    }
    QJsonDocument jsonDoc = QJsonDocument::fromVariant(newOne);
    QNetworkRequest req(QUrl(QString::fromStdString(url+"test.json")));
    req.setHeader(QNetworkRequest::ContentTypeHeader,QString("application/json"));
    networkManager->put(req,jsonDoc.toJson());
}
