

#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "editpage.h"
#include "calendar.h"
#include <QDialog>
#include <QHBoxLayout>
#include <QPixmap>
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

    Calendar *cal;
    QString selectedData;
    QTextCharFormat *highlight;
    QVector<DataStruct> listData ;
    QVBoxLayout *showData;
    DatabaseHandler *db;
    void addOne(DataStruct data);
    void fetchDataFromDb(QVBoxLayout *showData);


private slots:
    void selectDate(QDate date);
    void handleSelect();
    void createNew();
    void receiveRes(QString res);
    void on_calendarWidget_currentPageChanged(int year, int month);

};

#endif // HOMEPAGE_H
