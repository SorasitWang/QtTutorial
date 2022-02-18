#include "login.h"
#include "ui_login.h"

LogIn::LogIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
    connect(ui->label_2, SIGNAL(clicked()), this, SLOT(signup()));
}

LogIn::~LogIn()
{
    delete ui;
}

void LogIn::on_submit_clicked()
{
    QString userName = ui->userName->text();
    QString pwd = ui->password->text();

    if (true){
        close();
    }
}


void LogIn::signup(){

    Signup s(this);
    s.setModal(true);
    s.exec();
}

void LogIn::close(){
this->hide();
    HomePage w;
    w.setModal(true);
    w.exec();

}

