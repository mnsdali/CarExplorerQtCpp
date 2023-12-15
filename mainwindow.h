#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "car.h"
#include <QMainWindow>
#include <vector>
#include <QObject>
#include <QComboBox>
#include <QLineEdit>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    vector<Car> getCars();
    void setCars(vector<Car> buffCar);

private slots:
    void on_carSelector_currentIndexChanged(int index);

    void on_calcConsumptionRate_clicked();

private:
    Ui::MainWindow *ui;
    vector<Car> cars;
    QGraphicsScene* scene;
};
#endif // MAINWINDOW_H
