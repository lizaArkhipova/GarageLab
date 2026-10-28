#include "Car.h"

Car::Car() : Vehicle(), engineVolume(0.0), color("Unknown"), transmissionType("Unknown") { //конструкци€ без параментра
    cout << "[Car] Default constructor: " << endl;
}
 
Car::Car(const string& brand, const string& model, double engineVolume, //конструктор с параметрами
    const string& color, const string& transmissionType)
    : Vehicle(brand, model), engineVolume(engineVolume), color(color), transmissionType(transmissionType) { //параметра не сохран€ютс€ в кар, хран€тс€ вихайкл
    cout << "[Car] Parameterized constructor: " << brand << " " << model << endl;
}

Car::Car(const Car& other) //конструктор копировани€
    : Vehicle(other), engineVolume(other.engineVolume), //вихайкл вызывает конструктор копир базового класса. он копи брэнд и модел в офер.
    color(other.color), transmissionType(other.transmissionType) {
    cout << "[Car] Copy constructor: " << brand << " " << model << endl;
}

Car::~Car() { //деструктор 
    cout << "[Car] Destructor: " << brand << " " << model << endl;
}
//оператор присваивани€ 
Car& Car::operator=(const Car& other) {
    if (this != &other) {//проверка на самоприсваивание 
        Vehicle::operator=(other); //€ано вызываем оператор присваивани€ базового класса, чтобы скопировать брэнд и модел.
        engineVolume = other.engineVolume;//копируем пол€
        color = other.color;
        transmissionType = other.transmissionType;
        cout << "[Car] operator=: " << brand << " " << model << endl;
    }
    return *this;
}
//гет и сет модули
double Car::getEngineVolume() const { return engineVolume; }
string Car::getColor() const { return color; }
string Car::getTransmissionType() const { return transmissionType; }
void Car::setEngineVolume(double v) { engineVolume = v; }
void Car::setColor(const string& c) { color = c; }
void Car::setTransmissionType(const string& t) { transmissionType = t; }
//выводит всае пол€ . полиморфизм
void Car::display() const {
    cout << "    Car    " << endl;
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Engine volume: " << engineVolume << " L" << endl;
    cout << "Color: " << color << endl;
    cout << "Transmission: " << transmissionType << endl;
}
//считывает данные с клавы
void Car::input() {
    cout << "Enter car data:" << endl;
    cout << "Brand: "; cin >> brand;
    cout << "Model: "; cin >> model;
    cout << "Engine volume (L): "; cin >> engineVolume;
    cout << "Color: "; cin >> color;
    cout << "Transmission (manual/auto): "; cin >> transmissionType;
}
//сохранение данных  в файл 
void Car::saveToFile(ofstream& out) const {
    out << 1 << endl; //маркер типа
    Vehicle::saveToFile(out); //вызов базового класса
    out << engineVolume << endl;
    out << color << endl;
    out << transmissionType << endl;
}
//загрузка файла 
void Car::loadFromFile(ifstream& in) { //читает брэнд и модел через гетлайн 
    Vehicle::loadFromFile(in); //читает брэнд и модел через гетлайн 
    in >> engineVolume; //читает число, объем двигател€. оператор оставл€ет символ новой строки в буфере 
    in.ignore();//удал€етс€ этот символ 
    getline(in, color); //читает цвет
    getline(in, transmissionType); //читает  ѕѕ
}