
#include "editpage.h"



EditPage::EditPage(Ui::HomePage *u):
    ui(u)
{
    QVBoxLayout *layout = new QVBoxLayout();
    ui->centerWidget->setLayout(layout);
    this->des = new QLabel("Default");
    layout->addWidget(this->des);
    //layout->addWidget(new QPushButton());
}

EditPage::~EditPage()
{
    delete ui;
}
void EditPage::change(QString name){
    this->des->setText(name);

}
