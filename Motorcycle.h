#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle { //наследование публич
private: //уникальные поля мотоцикла
    double engineVolume;
    double enginePower;
    string terrainType;

public:
    Motorcycle(); //без параметров
    Motorcycle(const string& brand, const string& model, double engineVolume,//с параметрами
        double enginePower, const string& terrainType);
    Motorcycle(const Motorcycle& other);//копирование
    ~Motorcycle() override; //деструтор 

    Motorcycle& operator=(const Motorcycle& other);//оператор присваивания

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