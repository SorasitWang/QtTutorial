#include "calendar.h"
#include "homepage.h"
#include <QDate>
#include <QMessageBox>
#include <QCalendarWidget>
#include <QMessageBox>
#include <QTextCharFormat>
#include <HomePage.h>

Calendar:: Calendar(Ui::HomePage *u)
    : ui(u)
{

    ui->calendarWidget->setFixedWidth(ui->tabWidget->height()/1.63);
    ui->showMonth->setAlignment(Qt::AlignTop);
    ui->showMonth->setSpacing(0);
    //connect(ui->calendarWidget,SLOT(clicked(QDate)),this,SIGNAL(on_calendarWidget_clicked(QDate)));
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
}

void Calendar::initBtn(DataStruct data){
    QPushButton *dataClick = new QPushButton();
    QHBoxLayout *lay = new QHBoxLayout(dataClick);
    dataClick->setFixedHeight(30);
    lay->addWidget(new QLabel(data.title));
    ui->showMonth->addWidget(dataClick);
    //connect(dataClick,SIGNAL(cliked),this,SLOT(change));
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

    if (!monthData.contains(QPair<int,int>(m,y))){
        return ;
    }

    QList<DataStruct> dataM = monthData[QPair<int,int>(m,y)];
    for (int i=0;i<dataM.size();i++){
        initBtn(dataM[i]);
    }
}


/*void Calendar::on_calendarWidget_clicked(const QDate &date)
{
   //QMessageBox::warning(ui->centerWidget,"Warning",QString::number(date.year()));
   //ui->calendarWidget->setDateTextFormat(date,*highlight);
}
*/
