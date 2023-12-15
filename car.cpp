#include "car.h"
#include <iostream>
#include <string>

using namespace std;

    // Constructor
Car::Car(string _name, string _category, string _provider,
        double _batteryCapacity, double _range, double _topSpeed,
        double _seconds0_60mph, int _horsePower, int _seats, double _price, string _image)
        : name(_name), category(_category), provider(_provider),
        batteryCapacity(_batteryCapacity), range(_range), topSpeed(_topSpeed),
        seconds0_60mph(_seconds0_60mph), horsePower(_horsePower),
    seats(_seats), price(_price), image(_image) {}

    // Getters
string Car::getName() const { return name; }
string Car::getCategory() const { return category; }
string Car::getProvider() const { return provider; }
string Car::getImage() const { return image; }
double Car::getBatteryCapacity() const { return batteryCapacity; }
double Car::getRange() const { return range; }
double Car::getTopSpeed() const { return topSpeed; }
double Car::getSeconds0_60mph() const { return seconds0_60mph; }
int Car::getHorsePower() const { return horsePower; }
int Car::getSeats() const { return seats; }
double Car::getPrice() const { return price; }

// Setters
void Car::setName(string _name) { name = _name; }
void Car::setCategory(string _category) { category = _category; }
void Car::setProvider(string _provider) { provider = _provider; }
void Car::setImage(string _image) { image = _image; }
void Car::setBatteryCapacity(double _batteryCapacity) { batteryCapacity = _batteryCapacity; }
void Car::setRange(double _range) { range = _range; }
void Car::setTopSpeed(double _topSpeed) { topSpeed = _topSpeed; }
void Car::setSeconds0_60mph(double _seconds0_60mph) { seconds0_60mph = _seconds0_60mph; }
void Car::setHorsePower(int _horsePower) { horsePower = _horsePower; }
void Car::setSeats(int _seats) { seats = _seats; }
void Car::setPrice(double _price) { price = _price; }

