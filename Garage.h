#ifndef GARAGE_H
#define GARAGE_H

#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Bus.h"

class Garage {
private:
    Vehicle** vehicles; //указатель на указаль динамическая память
    int count;
    int capacity;


public:
    Garage();
    Garage(const Garage& other);
    ~Garage();

    Garage& operator=(const Garage& other);

    void resize();
    void addVehicle(Vehicle* v);
    void removeVehicle(int index);
    void displayAll() const;
    void displayVehicle(int index) const;
    void editVehicle(int index);
    void clear();

    int getCount() const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif