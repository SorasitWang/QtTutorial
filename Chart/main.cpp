#include "mainwindow.h"

#include <QApplication>
#include <QtCharts/QChartView>

// Used to draw bars representing data provided
// grouped into categories
#include <QtCharts/QBarSeries>

// Represents 1 set of bars in a bar chart
#include <QtCharts/QBarSet>

// Displays the color used to represent each
// QBarSet
#include <QtCharts/QLegend>

// Adds categories to the charts axes
#include <QtCharts/QBarCategoryAxis>

// Used to create stacked bar charts
#include <QtCharts/QHorizontalStackedBarSeries>

// Used to create a line chart
#include <QtCharts/QLineSeries>

// Used to change names on axis
#include <QtCharts/QCategoryAxis>

// Used to make Pie Charts
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

//QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*QBarSet *set0 = new QBarSet("A");
    QBarSet *set1 = new QBarSet("B");
    QBarSet *set2 = new QBarSet("C");
    QBarSet *set3 = new QBarSet("D");

    //assign value
    *set0 << 283 << 341 << 313 << 338 << 346 << 335;
    *set1 << 250 << 315 << 282 << 307 << 303 << 330;
    *set2 << 294 << 246 << 257 << 319 << 300 << 325;
    *set3 << 248 << 287 << 299 << 315 << 306 << 313;

    //create series
    QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);

    //create chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Demo");
    chart->setAnimationOptions(QChart::AllAnimations);

    //Label
    QStringList cat;
    cat << "2013" << "2014" << "2015" << "2016" << "2017" << "2018";

    //axis
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(cat);
    chart->createDefaultAxes();
    //label,series
    chart->setAxisY(axis,series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    //display
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window,QRgb(0x555555));
    pal.setColor(QPalette::WindowText,QRgb(0x404040));
    qApp->setPalette(pal);*/

    /**/

    /*QLineSeries *series = new QLineSeries();
    series->append(0,16);
    series->append(1,26);
    series->append(2,30);
    series->append(3,15);
    series->append(4,6);
    series->append(5,9);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();

    QFont font ;
    font.setPixelSize(16);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::black));
    chart->setTitle("Demo");

    QPen pen(QRgb(0x000000));
    pen.setWidth(5);
    series->setPen(pen);

    chart->setAnimationOptions(QChart::AllAnimations);

    QCategoryAxis *axisX = new QCategoryAxis();
    axisX->append("1986",0);
    axisX->append("1987",1);
    axisX->append("1988",2);
    axisX->append("1989",3);
    axisX->append("1990",4);
    axisX->append("1991",5);
    chart->setAxisX(axisX,series);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    */
    QPieSeries *series = new QPieSeries();
    series->append("Vegerables",.40);
    series->append("Beans",.20);
    series->append("Fruit",.15);
    series->append("Seeds",.10);
    series->append("Whole Grains",.05);

    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();

    QPieSlice *slice1 = series->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen,2));
    slice1->setBrush(Qt::green);

    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelVisible();
    QPieSlice *slice3 = series->slices().at(3);
    slice3->setLabelVisible();
    QPieSlice *slice4 = series->slices().at(4);
    slice4->setLabelVisible();

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("What Mek ate this week");
    chart->legend()->hide();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    MainWindow w;
    w.setCentralWidget(chartView);
    w.resize(420,300);
    w.show();
    return a.exec();
}
