#include "mainwindow.h"
#include "ui_mainwindow.h"


double calVal = 0.0;
bool divTrigger = false;
bool mulTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calVal));
    QPushButton *numButtons[10];
    for(int i=0;i<10;i++){
        QString butName = "Btn" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QPushButton *>(butName);
        connect(numButtons[i],SIGNAL(released()),this,
                SLOT(NumPressed()));

    }

    connect(ui->Plus,SIGNAL(released()),this,
            SLOT(MathButtonPressed()));
    connect(ui->Divide,SIGNAL(released()),this,
            SLOT(MathButtonPressed()));
    connect(ui->Multiply,SIGNAL(released()),this,
            SLOT(MathButtonPressed()));
    connect(ui->Minus,SIGNAL(released()),this,
            SLOT(MathButtonPressed()));

    connect(ui->Equal,SIGNAL(released()),this,
            SLOT(EqualButton()));

    connect(ui->ChangeSign,SIGNAL(released()),this,
            SLOT(ChangeNumberSign()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::NumPressed(){
    ///printf("click");
    QPushButton *btn = (QPushButton *)sender();
    QString butVal = btn->text();
    QString displayVal = ui->Display->text();
    if(displayVal.toDouble()==0
            ||displayVal.toDouble()==0.0){
        ui->Display->setText((butVal));
    }
    else{
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui->Display->setText((QString::number(dblNewVal,'g',16)));
    }

}

void MainWindow::EqualButton(){
    double sol = 0.0;
    double num = ui->Display->text().toDouble();
    printf("%d %d/n",sol,num);
    if (divTrigger){

        if (num==0) sol = 0.0;
        else sol = calVal / num;
    }
    else if (addTrigger) sol = calVal + num;
    else if (mulTrigger) sol = calVal * num;
    else if (subTrigger) sol = calVal / num;
    ui->Display->setText(QString::number(sol));



}
void MainWindow::MathButtonPressed(){
    divTrigger = false;
    mulTrigger = false;
    addTrigger = false;
    subTrigger = false;
    QPushButton *btn = (QPushButton *)sender();
    calVal = ui->Display->text().toDouble();
    QString butVal = btn->text();
    if (QString::compare("/",butVal,Qt::CaseSensitive)==0) divTrigger = true;
    else if (QString::compare("*",butVal,Qt::CaseSensitive)==0) mulTrigger = true;
    else if (QString::compare("+",butVal,Qt::CaseSensitive)==0) addTrigger = true;
    else if (QString::compare("-",butVal,Qt::CaseSensitive)==0) subTrigger = true;
    ui->Display->setText("");

}
void MainWindow::ChangeNumberSign(){
     QPushButton *btn = (QPushButton *)sender();
     double result = ui->Display->text().toDouble();
     result *= -1;
     ui->Display->setText(QString::number(result));

}
