#include "ui_homepage.h"
#include "homepage.h"

#include <HomePage.h>

#ifndef CALENDAR_H
#define CALENDAR_H


namespace Ui {
class Calendar;
}
class Calendar
{

public:
    Calendar(Ui::HomePage *ui);
     ~Calendar();
    void update(QMap<QDate,DataStruct> _listData);
    void showDate(QDate date);
    void changeMonth(int month,int year);
private :
    Ui::HomePage *ui;
    QMap<QDate,DataStruct> listData;
    QMap<QPair<int,int>,QList<DataStruct>> monthData;

    void initBtn(DataStruct data);

};

#endif // CALENDAR_H
