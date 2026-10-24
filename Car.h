#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    double engineVolume;
    string color;
    string transmissionType;

public:
    Car();
    Car(const string& brand, const string& model, double engineVolume,
        const string& color, const string& transmissionType);
    Car(const Car& other);
    ~Car() override;

    Car& operator=(const Car& other);

    double getEngineVolume() const;
    string getColor() const;
    string getTransmissionType() const;
    void setEngineVolume(double v);
    void setColor(const string& c);
    void setTransmissionType(const string& t);

    void display() const override;
    void input() override;

    void saveToFile(ofstream& out) const override;
    void loadFromFile(ifstream& in) override;
};

#endif