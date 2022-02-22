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

    showData = new QVBoxLayout();

    db = new DatabaseHandler(this);
    QPushButton *addNew = new QPushButton("Empty");
    this->db->getAll();
    this->fetchDataFromDb(showData);
    showData->addWidget(addNew);
    showData->setAlignment(Qt::AlignTop);
    showData->setSpacing(0);
    ui->scrollAreaWidgetContents_6->setLayout(showData);
    this->editPage =new EditPage(ui);
    this->highlight = new QTextCharFormat();
    this->highlight->setUnderlineStyle(QTextCharFormat::SingleUnderline);


    ui->calendarWidget->setFixedWidth(ui->tabWidget->height()/1.63);

    connect(addNew,SIGNAL(clicked()),this,SLOT(createNew()));



}

HomePage::~HomePage()
{
    delete ui;
}


void HomePage::addOne(DataStruct data){

     this->listData.append(data);
     QPixmap icon("");
     QPushButton *bBtn = new QPushButton();

    QLabel *img = new QLabel();
    img->setPixmap(icon);

   QLabel *des = new QLabel(data.description);
    QPushButton *dataClick = new QPushButton();
    dataClick->setObjectName(QString::number(listData.size()-1));
    connect(dataClick, SIGNAL(released()), this, SLOT(handleSelect()));
    //QFrame *dataFrame = new QFrame(dataClick);


     showData->insertWidget(-1,dataClick);


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
    this->editPage->change(listData[btn->objectName().toInt()]);


    //db->addOne(tmp);

    //printf("%s",butVal.toStdString());
}


void HomePage::fetchDataFromDb(QVBoxLayout *showData){

   /* for (int i=0;i<8;i++){
        addOne(this->listData,showData,QString::number(i));
    }*/
}


void HomePage::on_calendarWidget_clicked(const QDate &date)
{
    QMessageBox::warning(this,"Warning",QString::number(date.year()));
    ui->calendarWidget->setDateTextFormat(date,*highlight);
}

void HomePage::receiveRes(QString res){
     QStringList l = res.split(":{");
     QString id;
    QList<QString> keys = DataStruct::getKeys();
    id = l[0].sliced(1,l[0].size()-1);
qDebug() << l[0]<<"/n";
    int start=0,len=0;
    for (int j=1;j<l.size();j++){
        DataStruct newData;
        QStringList dataL;
        qDebug() << l[j]<<"/n";

        for (int i=1;i<keys.size();i++){
            start = l[j].indexOf(keys[i]+":") +keys[i].size()+1 ;
            if (i==keys.size()-1)
                len = l[j].indexOf("}")+1;
            else {
                len = l[j].indexOf(keys[i+1]+":") ;
            }
            dataL.append(l[j].sliced(start,len-1-start));

        }
        newData.setValue(id,dataL.at(1),dataL.at(2),dataL.at(3),dataL.at(4),dataL.at(0));
        if (j!=l.size()-1){
            id = l[j].sliced(l[j].indexOf("},"),l[j].size()-l[j].indexOf("},"));
            id = id.remove(0,2);
        }
        addOne(newData);

    }
}

void HomePage::createNew(){
    this->editPage->createNew();
}

