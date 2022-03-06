#include "stat.h"

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>

Stat::Stat(Ui::HomePage *u):
    ui(u)
{
    //update();
    label = new QFont();
    label->setPointSize(7);
    this->series = new QPieSeries();
    //series->append("Vegerables",.40);
    /*series->append("Beans",.20);
    series->append("Fruit",.15);
    series->append("Seeds",.10);
    series->append("Whole Grains",.05);*/

    /*QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();*/

    /*QPieSlice *slice1 = series->slices().at(1);
    slice1->setLabelVisible();
    slice1->setLabelFont(*label);

    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelVisible();
    slice2->setLabelFont(*label);
    QPieSlice *slice3 = series->slices().at(3);
    slice3->setLabelVisible();
    slice3->setLabelFont(*label);
    QPieSlice *slice4 = series->slices().at(4);
    slice4->setLabelVisible();
    slice4->setLabelFont(*label);*/

    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("What Mek ate this week");
    chart->legend()->hide();

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    /*QChartView *chartView1 = new QChartView(chart);
    chartView1->setRenderHint(QPainter::Antialiasing);*/
    //chartView->setParent(ui->statWidget1);
    ui->statLayout->addWidget(chartView);
    //ui->statLayout->addWidget(chartView1);


}

void Stat::update(QList<DataStruct> listData){
    QString type;
    int total = listData.size();
    cat.clear();
    for (int i=0;i<total;i++){
        type = listData.at(i).type;
        if (this->cat.value(type) == NULL){
            this->cat[type] = 1;
        }
        else{
             this->cat[type] += 1;
        }
    }
    series->clear();
    for (int i=0;i<cat.keys().size();i++){
        series->append(cat.keys()[i],cat[cat.keys()[i]]);
        QPieSlice *slice = series->slices().at(i);
        slice->setLabelVisible();
        slice->setLabelFont(*label);
    }
    //QChart *chart = new QChart();
    /*chart->removeAllSeries();
    chart->addSeries(series);*/
    //chart->setTitle("What Mek ate this week");
    //chart->legend()->hide();

    //QChartView *chartView = new QChartView(chart);
    //chartView->setRenderHint(QPainter::Antialiasing);*/

    qDebug() << "cat" << cat;
}
