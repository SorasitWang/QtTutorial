#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "editpage.h"

#include <QDialog>
#include <QHBoxLayout>
#include <QPixmap>
namespace Ui {
class HomePage;
}

struct dataStruct{
    QString titlle;
    QString desciption;
    QString img;
    QDate created;
    QDate deadline;

};

class HomePage: public QDialog
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

private:
    Ui::HomePage *ui;
    EditPage *editPage;

    QString selectedData;
    QTextCharFormat *highlight;
    QVector<dataStruct> listData ;

    void addOne(QVector<dataStruct>,QVBoxLayout *showData,QString name);
    void fetchDataFromDb(QVBoxLayout *showData);

private slots:
    void handleSelect();

    void on_calendarWidget_clicked(const QDate &date);
};

#endif // HOMEPAGE_H
