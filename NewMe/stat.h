#ifndef STAT_H
#define STAT_H
#include "databasehandler.h"
#include "ui_homepage.h"

#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>

namespace Ui {
class HomePage;
}

class Stat
{
public:

    explicit Stat(Ui::HomePage *ui);
    ~Stat();
    void update(QList<DataStruct> listData);
private :
    Ui::HomePage *ui;
    QFont *label;
    QList<DataStruct> data;
    QPieSeries *series;
    QMap<QString,int> cat;
    QList<QPieSlice> *slices;
    QChart *chart;
    QChartView *chartView;

};

#endif // STAT_H
