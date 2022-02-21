#include "homepage.h"
#include "ui_homepage.h"

#include <QStandardItem>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QSizePolicy>
#include <QMessageBox>
#include <QScrollBar>
#include <QScrollArea>
#include <editpage.h>
#include <QTextCharFormat>



using namespace std;
HomePage::HomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);

    QVBoxLayout *showData = new QVBoxLayout();

    db = new DatabaseHandler(this);

    this->db->getAll();
    this->fetchDataFromDb(showData);
    showData->setAlignment(Qt::AlignTop);
    showData->setSpacing(0);
    ui->scrollAreaWidgetContents_6->setLayout(showData);
    this->editPage =new EditPage(ui);
    this->highlight = new QTextCharFormat();
    this->highlight->setUnderlineStyle(QTextCharFormat::SingleUnderline);


    ui->calendarWidget->setFixedWidth(ui->tabWidget->height()/1.63);



}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::addOne(QVector<DataStruct> list,QVBoxLayout *showData,QString name){


     QPixmap icon("");
     QPushButton *bBtn = new QPushButton();

    QLabel *img = new QLabel();
    img->setPixmap(icon);

   QLabel *des = new QLabel(name);
    QPushButton *dataClick = new QPushButton();
    dataClick->setObjectName(name);
    connect(dataClick, SIGNAL(released()), this, SLOT(handleSelect()));
    //QFrame *dataFrame = new QFrame(dataClick);


     showData->addWidget(dataClick);


    QGridLayout *layoutData = new QGridLayout(dataClick);
    dataClick->setFixedHeight(100);
    layoutData->addWidget(img,0,0,2,1);
    layoutData->addWidget(bBtn,1,1,1,1);
    layoutData->addWidget(des,2,0,1,2);
    layoutData->setSpacing(0);


    //list.append(*data);
}

void HomePage::handleSelect(){
    QPushButton *btn = (QPushButton *)sender();
    QString butVal = btn->objectName();
    this->editPage->change(butVal);
    DataStruct tmp ;
    tmp.setValue("SOS","Helloworld","xxx","2023,1,1");
    db->addOne(tmp);

    //printf("%s",butVal.toStdString());
}


void HomePage::fetchDataFromDb(QVBoxLayout *showData){

    for (int i=0;i<8;i++){
        addOne(this->listData,showData,QString::number(i));
    }
}


void HomePage::on_calendarWidget_clicked(const QDate &date)
{
    QMessageBox::warning(this,"Warning",QString::number(date.year()));
    ui->calendarWidget->setDateTextFormat(date,*highlight);
}

void HomePage::receiveRes(QString res){

    qDebug() << res;
    qDebug() << res;
}

