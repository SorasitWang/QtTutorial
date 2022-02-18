#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QDialog>
#include <QHBoxLayout>
#include <QPixmap>
namespace Ui {
class HomePage;
}

class HomePage : public QDialog
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

private:
    Ui::HomePage *ui;
    void addOne(QVector<QWidget>,QVBoxLayout *showData,QString name);
    QString selectedData;
private slots:
    void handleSelect();

};

#endif // HOMEPAGE_H
