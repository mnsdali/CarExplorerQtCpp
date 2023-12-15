#include "mainwindow.h"
#include "car.h"

#include <QApplication>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

vector<Car> readCsv() {
    // Open the CSV file using a relative path
    ifstream inputFile("C:/Users/USER/OneDrive/Documents/CarQtProject/assets/carDataset.csv");

    // Check if the file is opened successfully
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return {};
    }

    // Create a vector to store Car objects
    vector<Car> cars;

    // Read the header line (assuming the first line contains column names)
    string header;
    getline(inputFile, header);

    // Read data from the file line by line
    string line;
    string name, category, provider, image;
    double batteryCapacity, range, topSpeed, seconds0_60mph;
    int horsePower, seats;
    double price;
    while (getline(inputFile, line)) {

        stringstream ss(line);
        string token;

        // Extract data from the CSV line using std::getline
        if (getline(ss, token, ',')) name = token;
        if (getline(ss, token, ',')) category = token;
        if (getline(ss, token, ',')) provider = token;
        if (getline(ss, token, ',')) batteryCapacity = stod(token);
        if (getline(ss, token, ',')) range = stod(token);
        if (getline(ss, token, ',')) topSpeed = stod(token);
        if (getline(ss, token, ',')) seconds0_60mph = stod(token);
        if (getline(ss, token, ',')) horsePower = stoi(token);
        if (getline(ss, token, ',')) seats = stoi(token);
        if (getline(ss, token, ',')) price = stod(token);
        if (getline(ss, token, ',')) image = token;

        // Create a Car object and add it to the vector
        cars.emplace_back(name, category, provider, batteryCapacity, range, topSpeed, seconds0_60mph, horsePower, seats, price, image);
    }

    // Close the file
    inputFile.close();

    return cars;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setCars(readCsv());
    w.show();
    return a.exec();
}
