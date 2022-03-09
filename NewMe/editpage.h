
#ifndef EDITPAGE_H
#define EDITPAGE_H
#include "ui_homepage.h"
//#include "HomePage.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include "databasehandler.h"
namespace Ui {
class HomePage;
}

class EditPage
{
public:

    explicit EditPage(Ui::HomePage *ui,DatabaseHandler *db);
    ~EditPage();
    void change(DataStruct focus,bool isClear);
    void createNew();
    void editProgress(int value);
    bool creating = true;
    bool editing = true;
    void readOnly(bool t);
    void cancel();
    void ok();
    void setType();
    void changeType(QString type);




private :
    Ui::HomePage *ui;
    QLabel *des;
    DataStruct now;
    QPixmap icon;
    DatabaseHandler *db;
    void changeBtnTab();
    void on_cancel_clicked();
    void on_ok_clicked();
    void setPercent(int value);
};

#endif // EDITPAGE_H
