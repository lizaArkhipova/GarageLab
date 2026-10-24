#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle {
private:
    double engineVolume;
    double enginePower;
    string terrainType;

public:
    Motorcycle();
    Motorcycle(const string& brand, const string& model, double engineVolume,
        double enginePower, const string& terrainType);
    Motorcycle(const Motorcycle& other);
    ~Motorcycle() override;

    Motorcycle& operator=(const Motorcycle& other);

    double getEngineVolume() const;
    double getEnginePower() const;
    string getTerrainType() const;
    void setEngineVolume(double v);
    void setEnginePower(double p);
    void setTerrainType(const string& t);

    void display() const override;
    void input() override;

    void saveToFile(ofstream& out) const override;
    void loadFromFile(ifstream& in) override;
};

#endif