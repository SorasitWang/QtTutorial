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
  void Calendar::update(QMap<QDate,QVector<DataStruct>> _listData){
      //clear hightlight date
      this->monthData.clear();
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
          for (int j=0;j<_listData[keys[i]].size();j++){
          DataStruct tmp = _listData[keys[i]][j];
          qDebug() << tmp.title;
          ui->calendarWidget->setDateTextFormat(tmp.deadline,*highlight);

          //add to monthData
          QPair<int,int> my = QPair<int,int>(tmp.deadline.month(),
                                             tmp.deadline.year());
          if(!monthData.contains(my))
               monthData[my] = QList<DataStruct>();
          monthData[my].append(tmp);
          }
      }

      listData = _listData;
      changeMonth(ui->calendarWidget->monthShown(),ui->calendarWidget->yearShown());
  }

  void Calendar::initBtn(DataStruct data,int idx,QVBoxLayout *sameDayLay){
      //if (newDate)
     // *sameDay = new QWidget();
     // QVBoxLayout *sameDayLay = new QVBoxLayout(sameDay);
      //QLabel *labelDay = new QLabel(data.deadline.toString());
      QPushButton *dataClick = new QPushButton();
      QHBoxLayout *lay = new QHBoxLayout(dataClick);
      dataClick->setFixedHeight(30);
      dataClick->setObjectName(data.id+"_"+QString::number(idx));
      lay->addWidget(new QLabel(data.title));
      //sameDayLay->addWidget(labelDay);
      sameDayLay->addWidget(dataClick);
      //ui->showMonth->addWidget(sameDay);

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
          delete child;
      }

      //if no sol in this month, show "None"
      if (!monthData.contains(QPair<int,int>(m,y))){
          ui->inMonth->setText("None");
          return ;
      }
      //init button in sol list
      bool createNewDate = true;
      QList<DataStruct> dataM = monthData[QPair<int,int>(m,y)];

      for (int i=0;i<dataM.size();i++){
          dataM[i].sort = "Deadline";
      }
      std::sort(dataM.begin(),dataM.end());

      int i = 0;
      while(i<dataM.size()){
          qDebug()<<i;
          //if (i==0 || dataM[i].deadline != dataM[i-1].deadline){
              QWidget *sameDay = new QWidget();
              QVBoxLayout *dayLay = new QVBoxLayout(sameDay);
              dayLay->addWidget(new QLabel(dataM[i].deadline.toString()));
              ui->showMonth->addWidget(sameDay);
              initBtn(dataM[i],i,dayLay);
              i++;
              while(i<dataM.size() && dataM[i].deadline == dataM[i-1].deadline){
                initBtn(dataM[i],i,dayLay);
                i++;
              }

          //
      }
/*      for (int i=0;i<dataM.size();i++){

          else{

          }
          qDebug()<<dataM[i].title;
          for (int j=i-1;j>0;j--){
              if (dataM[j].deadline == dataM[i].deadline){
                  initBtn(dataM[i],i,true);
                  createNewDate = false;
                  break;
              }
          }
          if (createNewDate)
               initBtn(dataM[i],i,false);


      }*/
      //show total sol
      ui->inMonth->setText("Total : "+QString::number(dataM.size()));

  }


  /*void Calendar::on_calendarWidget_clicked(const QDate &date)
  {
     //QMessageBox::warning(ui->centerWidget,"Warning",QString::number(date.year()));
     //ui->calendarWidget->setDateTextFormat(date,*highlight);
  }
  */




