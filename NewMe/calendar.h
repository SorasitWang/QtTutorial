
#ifndef CALENDAR_H
#define CALENDAR_H

#include "databasehandler.h"
#include "editpage.h"
#include "ui_homepage.h"
//#include "HomePage.h"
#include <QWidget>

namespace Ui {
class Calendar;
}

class Calendar : public QWidget
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr,Ui::HomePage *u = nullptr,EditPage *e = nullptr);
    ~Calendar();
    void update(QMap<QDate,DataStruct> _listData);
       void showDate(QDate date);
       void changeMonth(int month,int year);
private :
       Ui::HomePage *ui;
       EditPage *editPage;
       QMap<QDate,DataStruct> listData;
       QMap<QPair<int,int>,QList<DataStruct>> monthData;

       void initBtn(DataStruct data,int idx);
private slots:
       void change();

};

   #endif // CALENDAR_H
