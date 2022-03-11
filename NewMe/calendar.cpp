#include "calendar.h"
#include "ui_calendar.h"

#include <QTextCharFormat>

Calendar::Calendar(QWidget *parent,Ui::HomePage *u,EditPage *e) :
    QWidget(parent),
    ui(u),editPage(e)
{
    ui->calendarWidget->setFixedWidth(ui->tabWidget->height()/1.9);
      ui->showMonth->setAlignment(Qt::AlignTop);
      ui->showMonth->setSpacing(0);

      //changeMonth(ui->calendarWidget->monthShown(),ui->calendarWidget->yearShown());
      //connect(ui->calendarWidget,SLOT(clicked(QDate)),this,SIGNAL(on_calendarWidget_clicked(QDate)));
  }

Calendar::~Calendar(){
 delete ui;
}
  void Calendar::update(QMap<QDate,DataStruct> _listData){
      //clear hightlight date
      QMap<QDate, QTextCharFormat> decor = ui->calendarWidget->dateTextFormat();
      QList<QDate> keys = decor.keys();
      QTextCharFormat *normal = new QTextCharFormat();
      normal->setUnderlineStyle(QTextCharFormat::NoUnderline);

      QTextCharFormat *highlight = new QTextCharFormat();
      highlight->setUnderlineStyle(QTextCharFormat::SingleUnderline);
      highlight->setFontWeight(QFont::Black);
      for (int i=0;i<keys.size();i++){
          ui->calendarWidget->setDateTextFormat(keys[i],*normal);
      }
      //rehightlight date
      keys = _listData.keys();
      for (int i=0;i<keys.size();i++){
          qDebug() << _listData[keys[i]].deadline;
          ui->calendarWidget->setDateTextFormat(_listData[keys[i]].deadline,*highlight);

          //add to monthData
          QPair<int,int> my = QPair<int,int>(_listData[keys[i]].deadline.month(),
                                             _listData[keys[i]].deadline.year());
          if(!monthData.contains(my))
               monthData[my] = QList<DataStruct>();
          monthData[my].append(_listData[keys[i]]);
      }

      listData = _listData;
      changeMonth(ui->calendarWidget->monthShown(),ui->calendarWidget->yearShown());
  }

  void Calendar::initBtn(DataStruct data,int idx){
      QPushButton *dataClick = new QPushButton();
      QHBoxLayout *lay = new QHBoxLayout(dataClick);
      dataClick->setFixedHeight(30);
      dataClick->setObjectName(data.id+"_"+QString::number(idx));
      lay->addWidget(new QLabel(data.title));
      ui->showMonth->addWidget(dataClick);
      connect(dataClick,SIGNAL(clicked()),this,SLOT(change()));
  }

  void Calendar::change(){
      QPushButton *btn = (QPushButton *)sender();
      QList<QString> name = btn->objectName().split("_");
      int m = ui->calendarWidget->monthShown();
      int y = ui->calendarWidget->yearShown();
      QList<DataStruct> sameMonth = monthData[QPair<int,int>(m,y)];
      qDebug() << sameMonth.at(name[1].toInt()).title;
      editPage->change(sameMonth.at(name[1].toInt()),false);
  }
  void Calendar::showDate(QDate date){
      if (listData.contains(date)){
          //QMessageBox::warning(ui->centerWidget,"Warning",listData[date].title);
      }
      else{

      }


  }

  void Calendar::changeMonth(int m, int y){

      //clearn old prev month
      QLayoutItem *child;
      while ((child = ui->showMonth->takeAt(0)) != 0) {
          delete child->widget();
      }

      //if no sol in this month, show "None"
      if (!monthData.contains(QPair<int,int>(m,y))){
          ui->inMonth->setText("None");
          return ;
      }
      //init button in sol list
      QList<DataStruct> dataM = monthData[QPair<int,int>(m,y)];
      for (int i=0;i<dataM.size();i++){
          initBtn(dataM[i],i);
      }
      //show total sol
      ui->inMonth->setText("Total : "+QString::number(dataM.size()));

  }


  /*void Calendar::on_calendarWidget_clicked(const QDate &date)
  {
     //QMessageBox::warning(ui->centerWidget,"Warning",QString::number(date.year()));
     //ui->calendarWidget->setDateTextFormat(date,*highlight);
  }
  */




