#include "stat.h"

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>

#include <QBarCategoryAxis>
#include <QBarSet>
#include <QValueAxis>

Stat::Stat(Ui::HomePage *u):
    ui(u)
{
    //update();
    label = new QFont();
    label->setPointSize(7);
    this->pieSeries = new QPieSeries();
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

    pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Categorize by type");
    pieChart->legend()->hide();

    pieChartView = new QChartView(pieChart);
    pieChartView->setRenderHint(QPainter::Antialiasing);


    /*QChartView *chartView1 = new QChartView(chart);
    chartView1->setRenderHint(QPainter::Antialiasing);*/
    //chartView->setParent(ui->statWidget1);
    ui->statLayout->addWidget(pieChartView);


    barSeries = new QHorizontalStackedBarSeries();
    //create chart
    barChart = new QChart();
    barChart->setTitle("Total progress");
   // barChart->addSeries(barSeries);
    barChart->setAnimationOptions(QChart::AllAnimations);

    //QValueAxis *axisY = new QValueAxis();
   //axisY->setRange(0,100);
   //barChart->addAxis(axisY, Qt::AlignBottom);
   //barSeries->attachAxis(axisY);

   //barChart->axes(Qt::Vertical).first()->setRange(0,100 * 2);
    //axis
    axis = new QBarCategoryAxis();
    barChart->createDefaultAxes();
    //barChart->axes(Qt::Vertical).first()->setRange(0,100 * 2);
    //QValueAxis *axisY = qobject_cast<QValueAxis*>(barChart->axes(Qt::Vertical).first());
    //Q_ASSERT(axisY);
    //axisY->setLabelFormat("%.1f  ");
    //barChart->axes(Qt::Vertical).at(0)->setRange(0.0f,100.0f);
    //label,series
    barChart->addAxis(axis,Qt::AlignLeft);
    barChart->addSeries(barSeries);
    barChart->legend()->setVisible(false);

    //display
    barChartView = new QChartView(barChart);
    barChartView->setRenderHint(QPainter::Antialiasing);

   ui->statLayout->addWidget(barChartView);
}

void Stat::update(QList<DataStruct> listData){
    QString type;
    int total = listData.size();
    int percent = 0;
    cat.clear();
    for (int i=0;i<total;i++){
        type = listData.at(i).type;
        percent = listData.at(i).percent;
        if (this->cat.value(type).first == NULL){
            this->cat[type].first = 1;
            this->cat[type].second = percent;
        }
        else{
            this->cat[type].first += 1;
            this->cat[type].second += percent;
        }
    }

    //pie chart
    pieSeries->clear();
    for (int i=0;i<cat.keys().size();i++){
        pieSeries->append(cat.keys()[i] + " " + QString::number(cat[cat.keys()[i]].first),cat[cat.keys()[i]].first);
        QPieSlice *slice = pieSeries->slices().at(i);
        slice->setLabelVisible();
        slice->setLabelFont(*label);
    }


    //line
    barSeries = new QHorizontalStackedBarSeries();
    barChart->removeAllSeries();
    //barChart->removeAllSeries();
    barChart->removeAxis(axis);
    QStringList labelAxis;
    QList<QBarSet*> lBarSet;
    int maximum = 0;
    //barSeries->clear();
    QBarSet *max = new QBarSet("MAX");
   // max->set
    //max->append(100);
    //barSeries->append(max);
    //labelAxis.append("MAX");
    for (int i=0;i<cat.keys().size();i++){
        labelAxis.append(cat.keys()[i]);
        lBarSet.append(new QBarSet(cat.keys()[i]));
        for (int j=0;j<cat.keys().size();j++){
            int val = int(cat[cat.keys()[i]].second / cat[cat.keys()[i]].first);
            if (val>maximum) maximum = val;
            if (i==j)lBarSet[i]->append(val);
            else lBarSet[i]->append(0);
        }

        barSeries->append(lBarSet.at(i));
    }

    axis->clear();
    axis->append(labelAxis);
    //create series*/
    //barChart->createDefaultAxes();
    //barChart->setAxisY(axis,barSeries);
    QValueAxis *axisY = new QValueAxis();
   axisY->setRange(0,maximum);
   //axisY->setMax(100);
   barChart->addAxis(axisY, Qt::AlignBottom);
   //barSeries->attachAxis(axisY);
    barChart->addAxis(axis,Qt::AlignLeft);
    //barSeries->attachAxis(axis);
    barChart->addSeries(barSeries);


    //barChart->createDefaultAxes();

    //qDebug() << ;
}
