#ifndef STAT_H
#define STAT_H
#include "databasehandler.h"
#include "ui_homepage.h"

#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>
#include <QHorizontalStackedBarSeries>
#include <QBarCategoryAxis>

namespace Ui {
class HomePage;
}

class Stat
{
public:

    explicit Stat(Ui::HomePage *ui);
    ~Stat();
    void update(QVector<DataStruct> listData);
private :
    Ui::HomePage *ui;
    QFont *label;
    QList<DataStruct> data;
    QPieSeries *pieSeries;

    QHorizontalStackedBarSeries *barSeries;
    QBarCategoryAxis *axis;
    QMap<QString,QPair<int,int>> cat;
    QList<QPieSlice> *slices;
    QChart *pieChart , *barChart;
    QChartView *pieChartView , *barChartView;

};

#endif // STAT_H
