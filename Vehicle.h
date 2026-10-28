#ifndef VEHICLE_H  //защита от повторного подключения 
#define VEHICLE_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Vehicle {
protected: //доступ внутри класса и в классах наследников
    string brand;
    string model;

public:
    Vehicle();  //создает объект без параметров
    Vehicle(const string& brand, const string& model); //с параметрами
    Vehicle(const Vehicle& other); //копирует 
    virtual ~Vehicle();  //виртуальный деструктор 

    Vehicle& operator=(const Vehicle& other);  //перегрузка оператора =. позволяет делать присваивание объектов V1=V2

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