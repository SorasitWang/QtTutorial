
#include "editpage.h"



EditPage::EditPage(Ui::HomePage *u,DatabaseHandler *d):
    ui(u),db(d)
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

void EditPage::change(DataStruct focus,bool isClear){
    now = focus;
    qDebug() << focus.type << focus.title;
    if (!isClear){
        readOnly(true);
        icon = QPixmap(":/icon/res/"+focus.type.toLower()+".png");

        creating = false;
        editing = false;

        changeBtnTab();
    }
    setPercent(now.percent);
    ui->title->setText(focus.title);
    ui->type->setCurrentText(focus.type);
    ui->startDate->setText(focus.created.toString());
    ui->dateEdit->setDate(focus.deadline);

    ui->descriptionPlain->setPlainText(focus.description);


    //this->des->setText(focus.title);


}

void EditPage::createNew(){
    change(DataStruct(),true);
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
        if (!editing){
            ui->ok->setText("Edit");
            ui->cancel->setText("Delete");
        }
        else{
            ui->ok->setText("Update");
            ui->cancel->setText("Exit");
        }
    }

    if (creating || editing){
        ui->type->setEnabled(true);
        ui->dateEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        ui->dateEdit->setReadOnly(false);
        ui->descriptionPlain->setReadOnly(false);
        ui->title->setReadOnly(false);
        ui->title->setFrame(true);
        ui->slideProgress->setVisible(true);
    }
}

void EditPage::cancel(){

    if (creating){
        //clear all tmp data
        change(DataStruct(),true);

    }
    else{

        if (editing){
            //cancel collection
            change(now,false);
        }
        else{
            //delete collection
            changeBtnTab();
        }
        editing = !editing;
    }

}

void EditPage::ok(){
    //add new one to db
    if (creating){

        return;
    }

    if (editing){
        //update to db
    }
    else{
        //change ui to edit mode
        readOnly(false);



    }
    editing = !editing;
    changeBtnTab();
}

void EditPage::on_ok_clicked()
{
    if (creating){
        //add new

    }
    else{
        //edit
    }
}

void EditPage::setType(){
    ui->type->addItem("Healthy");
    ui->type->addItem("Study");
    ui->type->addItem("Money");

}

void EditPage::changeType(QString type){
     icon = QPixmap(":/icon/res/"+type.toLower()+".png");
     ui->icon->setPixmap(icon.scaled(ui->icon->width(),ui->icon->height(),Qt::KeepAspectRatio));
}



void EditPage::editProgress(int value){
    qDebug()<<value;
     ui->progressBar->setValue(value);
}

void EditPage::setPercent(int value){
    ui->progressBar->setValue(value);
    ui->slideProgress->setValue(value);
}

void EditPage::readOnly(bool t){
    if(t){
        ui->icon->setPixmap(icon.scaled(ui->icon->width(),ui->icon->height(),Qt::KeepAspectRatio));
        ui->title->setFrame(false);
        ui->title->setReadOnly(true);
        ui->dateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ui->descriptionPlain->setReadOnly(true);
        ui->slideProgress->setVisible(false);
        ui->dateEdit->setReadOnly(true);
        ui->type->setEnabled(false);
    }
    else{
        ui->descriptionPlain->setReadOnly(false);
        ui->title->setReadOnly(false);
        ui->dateEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        ui->dateEdit->setReadOnly(false);
        ui->type->setEnabled(true);
        ui->slideProgress->setVisible(true);
        ui->title->setFrame(true);
    }
}


