/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *Btn8;
    QPushButton *Btn6;
    QPushButton *Btn3;
    QPushButton *Btn4;
    QPushButton *Btn1;
    QPushButton *Plus;
    QPushButton *Btn7;
    QPushButton *Divide;
    QPushButton *Btn9;
    QPushButton *MemAdd;
    QPushButton *Btn5;
    QPushButton *Btn2;
    QPushButton *MemClear;
    QPushButton *Multiply;
    QPushButton *MemAdd_2;
    QPushButton *Clear;
    QPushButton *Btn0;
    QPushButton *ChangeSign;
    QPushButton *Minus;
    QPushButton *Equal;
    QLineEdit *Display;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(515, 314);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Btn8 = new QPushButton(centralwidget);
        Btn8->setObjectName(QString::fromUtf8("Btn8"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Btn8->sizePolicy().hasHeightForWidth());
        Btn8->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        Btn8->setFont(font);
        Btn8->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color : #A9A9A9;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(Btn8, 1, 1, 1, 1);

        Btn6 = new QPushButton(centralwidget);
        Btn6->setObjectName(QString::fromUtf8("Btn6"));
        sizePolicy.setHeightForWidth(Btn6->sizePolicy().hasHeightForWidth());
        Btn6->setSizePolicy(sizePolicy);
        Btn6->setFont(font);
        Btn6->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color : #A9A9A9;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(Btn6, 2, 2, 1, 1);

        Btn3 = new QPushButton(centralwidget);
        Btn3->setObjectName(QString::fromUtf8("Btn3"));
        sizePolicy.setHeightForWidth(Btn3->sizePolicy().hasHeightForWidth());
        Btn3->setSizePolicy(sizePolicy);
        Btn3->setFont(font);
        Btn3->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color : #A9A9A9;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(Btn3, 3, 2, 1, 1);

        Btn4 = new QPushButton(centralwidget);
        Btn4->setObjectName(QString::fromUtf8("Btn4"));
        sizePolicy.setHeightForWidth(Btn4->sizePolicy().hasHeightForWidth());
        Btn4->setSizePolicy(sizePolicy);
        Btn4->setFont(font);
        Btn4->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color : #A9A9A9;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(Btn4, 2, 0, 1, 1);

        Btn1 = new QPushButton(centralwidget);
        Btn1->setObjectName(QString::fromUtf8("Btn1"));
        sizePolicy.setHeightForWidth(Btn1->sizePolicy().hasHeightForWidth());
        Btn1->setSizePolicy(sizePolicy);
        Btn1->setFont(font);
        Btn1->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color : #A9A9A9;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(Btn1, 3, 0, 1, 1);

        Plus = new QPushButton(centralwidget);
        Plus->setObjectName(QString::fromUtf8("Plus"));
        sizePolicy.setHeightForWidth(Plus->sizePolicy().hasHeightForWidth());
        Plus->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        Plus->setFont(font1);
        Plus->setAutoFillBackground(false);
        Plus->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color: red;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(Plus, 3, 3, 1, 1);

        Btn7 = new QPushButton(centralwidget);
        Btn7->setObjectName(QString::fromUtf8("Btn7"));
        sizePolicy.setHeightForWidth(Btn7->sizePolicy().hasHeightForWidth());
        Btn7->setSizePolicy(sizePolicy);
        Btn7->setFont(font);
        Btn7->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color : #A9A9A9;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(Btn7, 1, 0, 1, 1);

        Divide = new QPushButton(centralwidget);
        Divide->setObjectName(QString::fromUtf8("Divide"));
        sizePolicy.setHeightForWidth(Divide->sizePolicy().hasHeightForWidth());
        Divide->setSizePolicy(sizePolicy);
        Divide->setFont(font1);
        Divide->setAutoFillBackground(false);
        Divide->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color: red;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(Divide, 1, 3, 1, 1);

        Btn9 = new QPushButton(centralwidget);
        Btn9->setObjectName(QString::fromUtf8("Btn9"));
        sizePolicy.setHeightForWidth(Btn9->sizePolicy().hasHeightForWidth());
        Btn9->setSizePolicy(sizePolicy);
        Btn9->setFont(font);
        Btn9->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color : #A9A9A9;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(Btn9, 1, 2, 1, 1);

        MemAdd = new QPushButton(centralwidget);
        MemAdd->setObjectName(QString::fromUtf8("MemAdd"));
        sizePolicy.setHeightForWidth(MemAdd->sizePolicy().hasHeightForWidth());
        MemAdd->setSizePolicy(sizePolicy);
        MemAdd->setFont(font1);
        MemAdd->setAutoFillBackground(false);
        MemAdd->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color: red;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(MemAdd, 1, 4, 1, 1);

        Btn5 = new QPushButton(centralwidget);
        Btn5->setObjectName(QString::fromUtf8("Btn5"));
        sizePolicy.setHeightForWidth(Btn5->sizePolicy().hasHeightForWidth());
        Btn5->setSizePolicy(sizePolicy);
        Btn5->setFont(font);
        Btn5->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color : #A9A9A9;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(Btn5, 2, 1, 1, 1);

        Btn2 = new QPushButton(centralwidget);
        Btn2->setObjectName(QString::fromUtf8("Btn2"));
        sizePolicy.setHeightForWidth(Btn2->sizePolicy().hasHeightForWidth());
        Btn2->setSizePolicy(sizePolicy);
        Btn2->setFont(font);
        Btn2->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color : #A9A9A9;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(Btn2, 3, 1, 1, 1);

        MemClear = new QPushButton(centralwidget);
        MemClear->setObjectName(QString::fromUtf8("MemClear"));
        sizePolicy.setHeightForWidth(MemClear->sizePolicy().hasHeightForWidth());
        MemClear->setSizePolicy(sizePolicy);
        MemClear->setFont(font1);
        MemClear->setAutoFillBackground(false);
        MemClear->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color: red;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(MemClear, 2, 4, 1, 1);

        Multiply = new QPushButton(centralwidget);
        Multiply->setObjectName(QString::fromUtf8("Multiply"));
        sizePolicy.setHeightForWidth(Multiply->sizePolicy().hasHeightForWidth());
        Multiply->setSizePolicy(sizePolicy);
        Multiply->setFont(font1);
        Multiply->setAutoFillBackground(false);
        Multiply->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color: red;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(Multiply, 2, 3, 1, 1);

        MemAdd_2 = new QPushButton(centralwidget);
        MemAdd_2->setObjectName(QString::fromUtf8("MemAdd_2"));
        sizePolicy.setHeightForWidth(MemAdd_2->sizePolicy().hasHeightForWidth());
        MemAdd_2->setSizePolicy(sizePolicy);
        MemAdd_2->setFont(font1);
        MemAdd_2->setAutoFillBackground(false);
        MemAdd_2->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color: red;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(MemAdd_2, 3, 4, 1, 1);

        Clear = new QPushButton(centralwidget);
        Clear->setObjectName(QString::fromUtf8("Clear"));
        sizePolicy.setHeightForWidth(Clear->sizePolicy().hasHeightForWidth());
        Clear->setSizePolicy(sizePolicy);
        Clear->setFont(font);
        Clear->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color : #A9A9A9;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(Clear, 4, 0, 1, 1);

        Btn0 = new QPushButton(centralwidget);
        Btn0->setObjectName(QString::fromUtf8("Btn0"));
        sizePolicy.setHeightForWidth(Btn0->sizePolicy().hasHeightForWidth());
        Btn0->setSizePolicy(sizePolicy);
        Btn0->setFont(font);
        Btn0->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color : #A9A9A9;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(Btn0, 4, 1, 1, 1);

        ChangeSign = new QPushButton(centralwidget);
        ChangeSign->setObjectName(QString::fromUtf8("ChangeSign"));
        sizePolicy.setHeightForWidth(ChangeSign->sizePolicy().hasHeightForWidth());
        ChangeSign->setSizePolicy(sizePolicy);
        ChangeSign->setFont(font);
        ChangeSign->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color : #A9A9A9;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(ChangeSign, 4, 2, 1, 1);

        Minus = new QPushButton(centralwidget);
        Minus->setObjectName(QString::fromUtf8("Minus"));
        sizePolicy.setHeightForWidth(Minus->sizePolicy().hasHeightForWidth());
        Minus->setSizePolicy(sizePolicy);
        Minus->setFont(font1);
        Minus->setAutoFillBackground(false);
        Minus->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color: red;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(Minus, 4, 3, 1, 1);

        Equal = new QPushButton(centralwidget);
        Equal->setObjectName(QString::fromUtf8("Equal"));
        sizePolicy.setHeightForWidth(Equal->sizePolicy().hasHeightForWidth());
        Equal->setSizePolicy(sizePolicy);
        Equal->setFont(font1);
        Equal->setAutoFillBackground(false);
        Equal->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"	background-color: red;\n"
"	color : green;\n"
"}\n"
"QPushButton:pressed {\n"
"	color : red;\n"
"}"));

        gridLayout->addWidget(Equal, 4, 4, 1, 1);

        Display = new QLineEdit(centralwidget);
        Display->setObjectName(QString::fromUtf8("Display"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Display->sizePolicy().hasHeightForWidth());
        Display->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(30);
        Display->setFont(font2);
        Display->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	color : rgb(109, 109, 109)\n"
"	\n"
"}"));
        Display->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(Display, 0, 0, 1, 5);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 515, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Btn8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        Btn6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        Btn3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        Btn4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        Btn1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        Plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        Btn7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        Divide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        Btn9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        MemAdd->setText(QCoreApplication::translate("MainWindow", "M+", nullptr));
        Btn5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        Btn2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        MemClear->setText(QCoreApplication::translate("MainWindow", "M-", nullptr));
        Multiply->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        MemAdd_2->setText(QCoreApplication::translate("MainWindow", "M", nullptr));
        Clear->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        Btn0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        ChangeSign->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        Minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        Equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        Display->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
