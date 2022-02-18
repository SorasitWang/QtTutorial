#include "signup.h"
#include "ui_signup.h"

#include <HomePage.h>
#include <QMessageBox>

Signup::Signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);
    connect(this,SIGNAL(closeLogin()),parent,SLOT(close()));
}

Signup::~Signup()
{
    delete ui;
}

void Signup::on_submit_clicked()
{
    QString name = ui->newUserName->text();
    QString pwd = ui->newPassword->text();
    if (QString::compare(pwd,ui->confrimPassword->text())){
        QMessageBox::warning(this,"Warning","Password not match");
        return;
    }
    //check if username already used
    else if (false){

    }
    //add to database
    this->close();
    emit(closeLogin());


}

