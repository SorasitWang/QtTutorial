
#include "homepage.h"
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
#include <QString>
#include <Qstring>




using namespace std;
HomePage::HomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomePage)

{
    ui->setupUi(this);

    showData = new QVBoxLayout();
    stat = new Stat(ui);
    db = new DatabaseHandler(this);
    cal = new Calendar(this,ui,new EditPage(ui,db));
    QPushButton *addNew = new QPushButton("Empty");
    this->db->getAll();
    this->fetchDataFromDb(showData);
    showData->insertWidget(0,addNew);
    showData->setAlignment(Qt::AlignTop);
    showData->setSpacing(0);
    ui->scrollAreaWidgetContents_6->setLayout(showData);
    this->editPage =new EditPage(ui,db);
    this->highlight = new QTextCharFormat();
    this->highlight->setUnderlineStyle(QTextCharFormat::SingleUnderline);

    ui->filterType->addItem("Healthy");
    ui->filterType->addItem("Study");
    ui->filterType->addItem("Money");

    ui->filterSort->addItem("Name");
    ui->filterSort->addItem("Deadline");
    ui->filterSort->addItem("Progress");


    connect(addNew,SIGNAL(clicked()),this,SLOT(createNew()));
    connect(ui->calendarWidget,SIGNAL(clicked(QDate)),this,SLOT(selectDate(QDate)));
    connect(ui->cancel,SIGNAL(released()),this,SLOT(cancel()));
    connect(ui->ok,SIGNAL(released()),this,SLOT(ok()));
    connect(ui->type,SIGNAL(currentTextChanged(QString)),this,SLOT(changeType(QString)));
    connect(ui->sortBy,SIGNAL(clicked()),this,SLOT(updateFilter()));
    connect(ui->filterType,SIGNAL(currentTextChanged(QString)),this,SLOT(updateFilter(QString)));
    connect(ui->filterSort,SIGNAL(currentTextChanged(QString)),this,SLOT(updateFilter(QString)));
    editPage->setType();
    //connect(ui->slideProgress,SIGNAL(valueChanged(value)),this,SLOT(editProgress(value)));


}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::ok(){
    qDebug()<<"OK" << num;
    num+=1;

    editPage->ok();

}

void HomePage::addOne(DataStruct data,int i){

     //this->listData.append(data);
     QPixmap icon("");
     QPushButton *bBtn = new QPushButton();

    QLabel *title = new QLabel(data.title);
    QLabel *type = new QLabel(data.type);

    QDate now =  QDate::currentDate();
    int daysLeft = now.daysTo(data.deadline);
    QString daysLeftTxt ;
    if (daysLeft <0)
        daysLeftTxt = "Already passed";
    else
        daysLeftTxt= QString::number(daysLeft)+QString(" days left");
    QLabel *deadline = new QLabel(daysLeftTxt);
    QPushButton *dataClick = new QPushButton();
    dataClick->setObjectName(QString::number(i));
    connect(dataClick, SIGNAL(released()), this, SLOT(handleSelect()));
    //QFrame *dataFrame = new QFrame(dataClick);

    QProgressBar *percent = new QProgressBar();
    percent->setValue(data.percent);
    percent->setTextVisible(false);
    percent->setFixedWidth(150);
     showData->addWidget(dataClick);
    scrollWidgets.append(dataClick);

    QGridLayout *layoutData = new QGridLayout(dataClick);
    dataClick->setFixedHeight(100);
    layoutData->addWidget(title,0,0);
    layoutData->addWidget(percent,1,1);
    layoutData->addWidget(type,1,0);
    layoutData->addWidget(deadline,0,1);
    layoutData->setSpacing(0);


    //list.append(*data);
}

void HomePage::handleSelect(){
    QPushButton *btn = (QPushButton *)sender();
    this->editPage->change(filteredData[btn->objectName().toInt()],false);
}


void HomePage::fetchDataFromDb(QVBoxLayout *showData){

   /* for (int i=0;i<8;i++){
        addOne(this->listData,showData,QString::number(i));
    }*/
}

void HomePage::selectDate(QDate date){
    this->cal->showDate(date);
}

void HomePage::receiveRes(QString res){
     QStringList l = res.split(":{");
     QString id;
    QList<QString> keys = DataStruct::getKeys();
    QVector<DataStruct> *tmpData = new QVector<DataStruct>();
    QMap<QDate,DataStruct> listData;
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

        newData.setValue(id,dataL.at(1),dataL.at(2),dataL.at(3),dataL.at(4),dataL.at(5),dataL.at(0));
        if (j!=l.size()-1){
            id = l[j].sliced(l[j].indexOf("},"),l[j].size()-l[j].indexOf("},"));
            id = id.remove(0,2);
        }
        this->listData.append(newData);
        this->filteredData.append(newData);
        tmpData->append(newData);
        addOne(newData,j-1);
        listData[newData.deadline] = newData;
    }

    //filtering
    //ui->filterSort->setCurrentText(nullptr);
    //ui->filterType->setCurrentText(nullptr);

    //filtering(*tmpData);
    /*for (int i=0;i<this->filteredData.size();i++){

        addOne(this->filteredData.at(i),i);
    }*/
    this->cal->update(listData);
    this->stat->update(listData.values());
    //this->stat->update(listData.values());

}

void HomePage::createNew(){
    this->editPage->createNew();
}

void HomePage::on_calendarWidget_currentPageChanged(int year, int month){

    cal->changeMonth(month,year);
}

void HomePage::changeType(QString txt){
    editPage->changeType(txt);
}
void HomePage::cancel(){
    editPage->cancel();
}

void HomePage::updateFilter(QString selected){
    updateFilter();

}
void HomePage::updateFilter(){
    //ui->sortBy->setChecked(true);
    qDebug()<<"filtering...";
    filtering(listData);
}

void HomePage::filtering(QVector<DataStruct> allData){
    //ui->filterType->setCurrentText("Money");
    this->filteredData.clear();

    qDebug()<< allData.size();
    for (int i=0;i<allData.size();i++){
       DataStruct data = allData.at(i);
        data.sort = ui->filterSort->currentText();
        if (ui->filterType->currentText() == nullptr)
            this->filteredData.append(data);
         //qDebug()<< allData.at(i).type << ui->filterType->currentText();
        else if (data.type == ui->filterType->currentText()){
            qDebug()<< allData.at(i).title;
            this->filteredData.append(data);
        }
    }
    //clear layout
    QLayoutItem *child;
     while ((child = this->showData->takeAt(1)) != nullptr) {

         delete child->widget(); // delete the widget
         delete child;   // delete the layout item
     }

   //sort



   QString type = ui->filterSort->currentText();

   /*if (type=="Deadline"){

       func = &HomePage::compareByDeadline;

   }
   else if (type=="Progress"){
       func = &HomePage::compareByProgress;

   }
   else {
       func = &HomePage::compareByName;

   }*/
   std::sort(this->filteredData.begin(), this->filteredData.end());
   if (ui->sortBy->isChecked())
    std::reverse(this->filteredData.begin(), this->filteredData.end());
   scrollWidgets.clear();
    for (int i=0;i<this->filteredData.size();i++){
        qDebug()<<  "add" << this->filteredData.at(i).title;
        addOne(this->filteredData.at(i),i);
    }

}

bool HomePage::compareByDeadline(const DataStruct &a,  const DataStruct &b)
{
    return a.deadline < b.deadline;
}

bool HomePage::compareByName(const DataStruct &a, const DataStruct &b)
{
    return a.title < b.title;
}

bool HomePage::compareByProgress(const DataStruct &a, const DataStruct &b)
{
    return a.percent < b.percent;
}
