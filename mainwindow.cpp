#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "car.h"


#include <QPixmap>
#include <QMessageBox>
#include <QIcon>

const string iconPath = "C:/Users/USER/OneDrive/Documents/CarQtProject/assets/carify.png";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //set title and Icon
    setWindowTitle(QString::fromStdString("Carify"));
    QIcon myIcon(QString::fromStdString(iconPath));
    setWindowIcon(myIcon);


    setStyleSheet("background-color: #333333; color: #FFFFFF;");
    // Set a darker header background
    ui->menubar->setStyleSheet("background-color: #202020; color: #FFFFFF;");  // Darker gray background, white text

    ui->carImg->setStyleSheet("border: 0px;");
    ui->carImg->setFixedSize(480, 300);
    ui->carImg->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->carImg->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene(this);


}

MainWindow::~MainWindow()
{
    delete ui;

}

vector<Car> MainWindow::getCars()
{
    return this->cars;
}

void MainWindow::setCars(vector<Car> buffCar)
{
    this->cars = buffCar;


    if (ui->carSelector->count() != 0){
        ui->carSelector->clear();
    }


    for (const auto& car : cars) {
        ui->carSelector->addItem(QString::fromStdString(car.getName()));
    }

    qDebug() << "Number of items in carSelector: " << ui->carSelector->count();
}

void MainWindow::on_carSelector_currentIndexChanged(int index)
{
    if (index >= 0 && index < cars.size()) {
        const Car& selectedCar = cars[index];

        // Update the input fields with the characteristics of the selected car
        ui->category->setText(QString::fromStdString(selectedCar.getCategory()));
        ui->provider->setText(QString::fromStdString(selectedCar.getProvider()));
        ui->batteryCapacity->setText(QString::number(selectedCar.getBatteryCapacity()));
        ui->range->setText(QString::number(selectedCar.getRange()));
        ui->topSpeed->setText(QString::number(selectedCar.getTopSpeed()));
        ui->seconds0_60mph->setText(QString::number(selectedCar.getSeconds0_60mph()));
        ui->horsepower->setText(QString::number(selectedCar.getHorsePower()));
        ui->price->setText(QString::number(selectedCar.getPrice()));
        if (ui->carImg->scene()) {
            ui->carImg->scene()->clear();
        }
        QString imagePath = "C:/Users/USER/OneDrive/Documents/CarQtProject/assets/" + QString::fromStdString(selectedCar.getImage());
        QPixmap image(imagePath);

        scene->addPixmap(image);


        ui->carImg->setScene(scene);
        ui->carImg->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);

    }
}


void MainWindow::on_calcConsumptionRate_clicked()
{
    double range = cars[ui->carSelector->currentIndex()].getRange();
    double battery_capacity = cars[ui->carSelector->currentIndex()].getBatteryCapacity();

    double energy_consumption_rate = battery_capacity / range;

    if (energy_consumption_rate >= 0.25)
    {
        QMessageBox::warning(
            this,  // <-- Provide the parent widget here
            tr("High Energy Consumption"),
            tr("Energy Consumption Rate: %1 kWh/mile\n\nVehicles in this category may have a higher energy consumption rate, potentially leading to shorter ranges for a given battery capacity. This could be due to factors like larger size, less aerodynamic design, or less energy-efficient systems.").arg(QString::number(energy_consumption_rate))
            );
    }
    else if (energy_consumption_rate < 0.25 && energy_consumption_rate >= 0.15)
    {
        QMessageBox::warning(
            this,  // <-- Provide the parent widget here
            tr("Moderate Energy Consumption"),
            tr("Energy Consumption Rate: %1 kWh/mile\n\nThis is a common range for many electric vehicles, providing a good balance between energy efficiency and practical range. Vehicles in this category often cover various driving needs effectively.").arg(QString::number(energy_consumption_rate))
            );
    }
    else
    {
        QMessageBox::information(
            this,  // <-- Provide the parent widget here
            tr("Low Energy Consumption"),
            tr("Energy Consumption Rate: %1 kWh/mile\n\nVehicles with a lower energy consumption rate are typically more energy-efficient, resulting in longer ranges for a given battery capacity. This can be attributed to factors like aerodynamic design, lightweight construction, and advanced energy management systems.").arg(QString::number(energy_consumption_rate))
            );
    }
}
