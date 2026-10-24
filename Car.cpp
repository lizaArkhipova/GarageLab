#include "Car.h"

Car::Car() : Vehicle(), engineVolume(0.0), color("Unknown"), transmissionType("Unknown") {
    cout << "[Car] Default constructor: " << endl;
}

Car::Car(const string& brand, const string& model, double engineVolume,
    const string& color, const string& transmissionType)
    : Vehicle(brand, model), engineVolume(engineVolume), color(color), transmissionType(transmissionType) {
    cout << "[Car] Parameterized constructor: " << brand << " " << model << endl;
}

Car::Car(const Car& other)
    : Vehicle(other), engineVolume(other.engineVolume),
    color(other.color), transmissionType(other.transmissionType) {
    cout << "[Car] Copy constructor: " << brand << " " << model << endl;
}

Car::~Car() {
    cout << "[Car] Destructor: " << brand << " " << model << endl;
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        Vehicle::operator=(other);
        engineVolume = other.engineVolume;
        color = other.color;
        transmissionType = other.transmissionType;
        cout << "[Car] operator=: " << brand << " " << model << endl;
    }
    return *this;
}

double Car::getEngineVolume() const { return engineVolume; }
string Car::getColor() const { return color; }
string Car::getTransmissionType() const { return transmissionType; }
void Car::setEngineVolume(double v) { engineVolume = v; }
void Car::setColor(const string& c) { color = c; }
void Car::setTransmissionType(const string& t) { transmissionType = t; }

void Car::display() const {
    cout << "=== Car ===" << endl;
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Engine volume: " << engineVolume << " L" << endl;
    cout << "Color: " << color << endl;
    cout << "Transmission: " << transmissionType << endl;
}

void Car::input() {
    cout << "Enter car data:" << endl;
    cout << "Brand: "; cin >> brand;
    cout << "Model: "; cin >> model;
    cout << "Engine volume (L): "; cin >> engineVolume;
    cout << "Color: "; cin >> color;
    cout << "Transmission (manual/auto): "; cin >> transmissionType;
}

void Car::saveToFile(ofstream& out) const {
    out << 1 << endl;
    Vehicle::saveToFile(out);
    out << engineVolume << endl;
    out << color << endl;
    out << transmissionType << endl;
}

void Car::loadFromFile(ifstream& in) {
    Vehicle::loadFromFile(in);
    in >> engineVolume;
    in.ignore();
    getline(in, color);
    getline(in, transmissionType);
}