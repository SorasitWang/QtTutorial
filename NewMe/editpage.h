
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

    explicit EditPage(Ui::HomePage *ui);
    ~EditPage();
    void change(DataStruct focus);
    void createNew();
    void editProgress(int value);
    bool creating = true;





private :
    Ui::HomePage *ui;
    QLabel *des;

    void changeBtnTab();
    void on_cancel_clicked();
    void on_ok_clicked();
    void setPercent(int value);
};

#endif // EDITPAGE_H
