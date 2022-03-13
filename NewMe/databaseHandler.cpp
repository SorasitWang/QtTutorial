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
        QString re;
        re = networkReply->readAll().replace(before,after);

        qDebug() << re;

        emit sendRes(re);
}

void DatabaseHandler::getAll(){
    char *before = "\"";
    char *after = "";
    QString re = "{\"1\":{\"created\":\"2022.5.3\",\"deadline\":\"2022.10.3\",\"description\":\"for pat1!\",\"percent\":55,\"title\":\"study\",\"type\":\"Money\"},\"-MwQSbfiycW0amw7zHCZ\":{\"created\":\"2022.02.02\",\"deadline\":\"2023.01.01\",\"description\":\"Helloworld\",\"percent\":75,\"title\":\"aa\",\"type\":\"Healthy\"},\"-MwQgJIEAmiMnBbUt6Bt\":{\"created\":\"2022.02.22\",\"deadline\":\"2022.03.03\",\"description\":\"Helloworld\",\"percent\":90,\"title\":\"sos\",\"type\":\"Money\"}}";
    re = re.replace(before,after);
    //emit sendRes(re);

    //return ;

    QString qurl = url+QString("test.json");
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
    QNetworkRequest req(QUrl(url+QString("test.json")));
    req.setHeader(QNetworkRequest::ContentTypeHeader,QString("application/json"));
    qDebug() << jsonDoc;
    networkManager->post(req,jsonDoc.toJson());
    connect(networkReply,&QNetworkReply::readyRead,this,&DatabaseHandler::networkReplyReadyRead);

}
void DatabaseHandler::deleteOne(DataStruct data){
    //data.id = "11";
    QNetworkRequest req(QUrl(url + QString("test/") + data.id + ".json"));
    req.setHeader(QNetworkRequest::ContentTypeHeader,QString("application/json"));
    networkManager->deleteResource(req);
}

void DatabaseHandler::updateOne(DataStruct data){
    /*data.title = "changed";
    data.percent = 55;
    data.type = "Money";
    data.description = "for pat5!";*/
    QVariantMap newOne;
    QList<QString> keys = data.getKeys();
    for(int i=0;i<keys.size();i++){
        newOne[keys[i]] = data.getValue(keys[i]);
    }
    QJsonDocument jsonDoc = QJsonDocument::fromVariant(newOne);
    QNetworkRequest req(QUrl(url+QString("test/1.json")));
    req.setHeader(QNetworkRequest::ContentTypeHeader,QString("application/json"));
    networkManager->put(req,jsonDoc.toJson());
}
