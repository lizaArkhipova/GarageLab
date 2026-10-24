#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Vehicle {
protected:
    string brand;
    string model;

public:
    Vehicle();
    Vehicle(const string& brand, const string& model);
    Vehicle(const Vehicle& other);
    virtual ~Vehicle();

    Vehicle& operator=(const Vehicle& other);

    string getBrand() const;
    string getModel() const;
    void setBrand(const string& brand);
    void setModel(const string& model);

    virtual void display() const = 0;
    virtual void input() = 0;

    virtual void saveToFile(ofstream& out) const;
    virtual void loadFromFile(ifstream& in);
};

#endif