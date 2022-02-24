
#include "editpage.h"



EditPage::EditPage(Ui::HomePage *u):
    ui(u)
{    
    changeBtnTab();
    //this->des = new QLabel("Default");
    //ui->centerLayout->addWidget(this->des);
    //layout->addWidget(new QPushButton());
}

EditPage::~EditPage()
{
    delete ui;
}

void EditPage::change(DataStruct focus){

    qDebug() << creating << focus.title;

    //this->des->setText(focus.title);
    creating = false;
    changeBtnTab();
}

void EditPage::createNew(){
    change(DataStruct());
    creating = true;
    changeBtnTab();
    //set btn
    //addOne(DataStruct());
    qDebug() << "add";
}

void EditPage::changeBtnTab(){
    if (creating){
       ui->ok->setText("Add");
       ui->cancel->setText("Clear");
    }
    else{
        ui->ok->setText("Update");
        ui->cancel->setText("Delete");
    }
}


void EditPage::on_cancel_clicked()
{
    if (creating){
        //clear all tmp data

    }
    else{
        //delete collection
    }
}


void EditPage::on_ok_clicked()
{
    if (creating){
        //clear all tmp data

    }
    else{
        //delete collection
    }
}





