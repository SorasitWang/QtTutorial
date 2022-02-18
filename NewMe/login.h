#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"
#include "homepage.h"
#include "signup.h"

namespace Ui {
class LogIn;
}

class LogIn : public QDialog
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = nullptr);
    ~LogIn();

private slots:
    void on_submit_clicked();
    void signup();
    void close();

private:
    Ui::LogIn *ui;
};

#endif // LOGIN_H
