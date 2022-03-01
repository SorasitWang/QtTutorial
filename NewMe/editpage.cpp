
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
    now = focus;
    qDebug() << focus.created.toString() << focus.title;
    setPercent(now.percent);
    ui->title->setText(focus.title);
    ui->title->setFrame(false);
    ui->title->setReadOnly(true);
    ui->startDate->setText(focus.created.toString());
    ui->dateEdit->setDate(focus.deadline);
    ui->dateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->dateEdit->setReadOnly(true);
    ui->descriptionPlain->setPlainText(focus.description);
    ui->descriptionPlain->setReadOnly(true);
    ui->slideProgress->setVisible(false);

    //this->des->setText(focus.title);
    creating = false;
    editing = false;
    changeBtnTab();
}

void EditPage::createNew(){
    change(DataStruct());
    creating = true;
    changeBtnTab();
    setPercent(0);
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

    if (creating || editing){
        ui->dateEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        ui->dateEdit->setReadOnly(false);
        ui->descriptionPlain->setReadOnly(false);
        ui->title->setReadOnly(false);
        ui->title->setFrame(true);
        ui->slideProgress->setVisible(true);
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






void EditPage::editProgress(int value){
    qDebug()<<value;
     ui->progressBar->setValue(value);
}

void EditPage::setPercent(int value){
    ui->progressBar->setValue(value);
    ui->slideProgress->setValue(value);
}


