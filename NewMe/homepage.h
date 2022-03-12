

#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "editpage.h"
#include "calendar.h"
#include <QDialog>
#include <QHBoxLayout>
#include <QPixmap>
#include <Stat.h>
#include "databasehandler.h"
namespace Ui {
class HomePage;
}



class HomePage: public QDialog
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();
    EditPage *editPage;

private:
    Ui::HomePage *ui;
    Stat *stat;
    Calendar *cal;
    QString selectedData;
    QTextCharFormat *highlight;
    QVector<DataStruct> listData ;
     QVector<DataStruct> filteredData ;
    QVector<QWidget*> scrollWidgets;
    QVBoxLayout *showData;
    DatabaseHandler *db;
    static bool (HomePage::*func)(const DataStruct&,const DataStruct&);

    void addOne(DataStruct data,int i);
    void fetchDataFromDb(QVBoxLayout *showData);
    void filtering(QVector<DataStruct> tmpData);
    bool compareByDeadline( const DataStruct &a,const DataStruct &b);
    bool compareByProgress(const DataStruct &a,const DataStruct &b);
    bool compareByName(const DataStruct &a,const DataStruct &b);


    int num=0;


private slots:
    void checkDeadline(QDate date);
    void selectDate(QDate date);
    void handleSelect();
    void createNew();
    void receiveRes(QString res);
    void on_calendarWidget_currentPageChanged(int year, int month);
    void cancel();
    void ok();
    void changeType(QString txt);
    void updateFilter(QString selected);
    void updateFilter();

};

#endif // HOMEPAGE_H
