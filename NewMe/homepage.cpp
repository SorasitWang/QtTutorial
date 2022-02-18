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

using namespace std;
HomePage::HomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomePage)
{
    QHBoxLayout *topWidgetLayout = new QHBoxLayout(this);
    //QVBoxLayout *l = new QVBoxLayout();
    QVBoxLayout *c = new QVBoxLayout();
    QVBoxLayout *r = new QVBoxLayout();

    //
    QVBoxLayout *showData = new QVBoxLayout();
    //QScrollBar *scroll = new QScrollBar(showData);
    QVector<QWidget> listData ;

    showData->setAlignment(Qt::AlignTop);
    showData->setSpacing(0);

    c->setAlignment(Qt::AlignTop);
    c->setSpacing(0);

    r->setAlignment(Qt::AlignTop);
    r->setSpacing(0);
    /*QPushButton *test = new QPushButton();
    QPushButton *test1 = new QPushButton();
    connect(test1,SIGNAL(released()), this, SLOT(handleSelect()));
    connect(test, SIGNAL(released()), this, SLOT(handleSelect()));*/

    //QFrame *dataFrame = new QFrame(dataClick);



    addOne(listData,showData,"One");

     addOne(listData,showData,"Two");
      addOne(listData,c,"Three");
      addOne(listData,r,"Four");
    //addOne(listData,new QVBoxLayout(l));
    //showData->addWidget(bBtn);
    topWidgetLayout->addLayout(showData);
    topWidgetLayout->addLayout(c);
    topWidgetLayout->addLayout(r);

    topWidgetLayout->setSpacing(0);
    //topWidgetLayout->addStretch(1); // add the stretch
    //a->setFixedWidth(300);

    ui->setupUi(this);
    /*QHBoxLayout *tmp = new QHBoxLayout(this);
    tmp->setObjectName("Tmp");
    ui->list->addLayout(tmp);

    tmp->addWidget(new QPushButton("Hi"));*/
    //ui->listWidget->addItem(new QListWidgetItem(QString("ssss")));
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::addOne(QVector<QWidget> list,QVBoxLayout *showData,QString name){


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
    //dataFrame->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Fixed);
    //dataClick->setFixedWidth(dataFrame->width());
    //dataClick->setFixedHeight(dataFrame->height());
    //dataClick->setFlat(true);
   /* dataClick->setStyleSheet(QString("border-style: outset;border-width: 2px;"
                                "border-radius: 10px;border-color: beige;"
                                "font: bold 14px;min-width: 10em;"
                                "padding: 6px;"));*/
    //dataFrame->setFrameShape(QFrame::Box);
   //dataFrame->setFrameShadow(QFrame::Plain);
    layoutData->addWidget(img,0,0,2,1);
    layoutData->addWidget(bBtn,1,1,1,1);
    layoutData->addWidget(des,2,0,1,2);
    layoutData->setSpacing(0);


    //list.append(*data);
}

void HomePage::handleSelect(){
    QPushButton *btn = (QPushButton *)sender();
    QString butVal = btn->objectName();
    QMessageBox::warning(this,"Warning",butVal);
    //printf("%s",butVal.toStdString());
}



