#include "ui_homepage.h"
#include "HomePage.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>
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
    void change(QString name);
private :
    Ui::HomePage *ui;
    QLabel *des;


};

#endif // EDITPAGE_H
