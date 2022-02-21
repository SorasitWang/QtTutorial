#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "editpage.h"

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

private:
    Ui::HomePage *ui;
    EditPage *editPage;

    QString selectedData;
    QTextCharFormat *highlight;
    QVector<DataStruct> listData ;

    DatabaseHandler *db;
    void addOne(QVector<DataStruct>,QVBoxLayout *showData,QString name);
    void fetchDataFromDb(QVBoxLayout *showData);

private slots:
    void handleSelect();
    void receiveRes(QString res);
    void on_calendarWidget_clicked(const QDate &date);
};

#endif // HOMEPAGE_H
