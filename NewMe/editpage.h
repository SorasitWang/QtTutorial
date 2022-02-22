#include "ui_homepage.h"
#include "HomePage.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include "databasehandler.h"
#ifndef EDITPAGE_H
#define EDITPAGE_H
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

private :
    Ui::HomePage *ui;
    QLabel *des;
    bool creating = true;
    void changeBtnTab();




    void on_cancel_clicked();
    void on_ok_clicked();
};

#endif // EDITPAGE_H
