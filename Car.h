#ifndef CAR_H
#define CAR_H

#include "Vehicle.h" //от какого класса мы наследуем, и чтобы видел все поля и методы
//пример инкапсуляции
class Car : public Vehicle { //класс кар от наследования 
private: //поля скрыты от внешнего кода, доступ только через гет и сет. это инкапсуляция
    double engineVolume;
    string color;
    string transmissionType;

public:
    Car(); //без параметров
    Car(const string& brand, const string& model, double engineVolume,
        const string& color, const string& transmissionType); //с параметрами
    Car(const Car& other); //копирует
    ~Car() override; //деструктор, выдаст ошибка если не правильно

    Car& operator=(const Car& other);//переопределение присваивания

    double getEngineVolume() const; //гет для чтения, сет для записи. 
    string getColor() const; //конст так как не изменяют состояние объекта
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