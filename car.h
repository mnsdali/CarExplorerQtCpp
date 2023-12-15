// car.h
#ifndef CAR_H
#define CAR_H

#include <string>

using namespace std;

class Car {
private:
    string name;
    string category;
    string provider;
    string image;
    double batteryCapacity;
    double range;
    double topSpeed;
    double seconds0_60mph;
    int horsePower;
    int seats;
    double price;

public:
    // Constructor
    Car(string _name, string _category, string _provider,
        double _batteryCapacity, double _range, double _topSpeed,
        double _seconds0_60mph, int _horsePower, int _seats, double _price, string _image);

    // Getters
    string getName() const;
    string getCategory() const;
    string getProvider() const;
    string getImage() const;
    double getBatteryCapacity() const;
    double getRange() const;
    double getTopSpeed() const;
    double getSeconds0_60mph() const;
    int getHorsePower() const;
    int getSeats() const;
    double getPrice() const;

    // Setters
    void setName(string _name);
    void setCategory(string _category);
    void setProvider(string _provider);
    void setImage(string _image);
    void setBatteryCapacity(double _batteryCapacity);
    void setRange(double _range);
    void setTopSpeed(double _topSpeed);
    void setSeconds0_60mph(double _seconds0_60mph);
    void setHorsePower(int _horsePower);
    void setSeats(int _seats);
    void setPrice(double _price);
};

#endif // CAR_H
