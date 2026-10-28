#include "Motorcycle.h"

Motorcycle::Motorcycle() : Vehicle(), engineVolume(0.0), enginePower(0.0), terrainType("Unknown") {
    cout << "[Motorcycle] Default constructor: "  << endl;
}

Motorcycle::Motorcycle(const string& brand, const string& model, double engineVolume,
    double enginePower, const string& terrainType)
    : Vehicle(brand, model), engineVolume(engineVolume),
    enginePower(enginePower), terrainType(terrainType) {
    cout << "[Motorcycle] Parameterized constructor: " << brand << " " << model << endl;
}

Motorcycle::Motorcycle(const Motorcycle& other)
    : Vehicle(other), engineVolume(other.engineVolume),
    enginePower(other.enginePower), terrainType(other.terrainType) {
    cout << "[Motorcycle] Copy constructor: " << brand << " " << model << endl;
}

Motorcycle::~Motorcycle() {
    cout << "[Motorcycle] Destructor: " << brand << " " << model << endl;
}
//оператор присваивания
Motorcycle& Motorcycle::operator=(const Motorcycle& other) {
    if (this != &other) {
        Vehicle::operator=(other);
        engineVolume = other.engineVolume;
        enginePower = other.enginePower;
        terrainType = other.terrainType;
        cout << "[Motorcycle] operator=: " << brand << " " << model << endl;
    }
    return *this;
}
//гет и сет методы
double Motorcycle::getEngineVolume() const { return engineVolume; }
double Motorcycle::getEnginePower() const { return enginePower; }
string Motorcycle::getTerrainType() const { return terrainType; }
void Motorcycle::setEngineVolume(double v) { engineVolume = v; }
void Motorcycle::setEnginePower(double p) { enginePower = p; }
void Motorcycle::setTerrainType(const string& t) { terrainType = t; }

void Motorcycle::display() const {
    cout << "    Motorcycle   " << endl;
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Engine volume: " << engineVolume << " cc" << endl;
    cout << "Power: " << enginePower << " hp" << endl;
    cout << "Terrain type: " << terrainType << endl;
}

void Motorcycle::input() {
    cout << "Enter motorcycle data:" << endl;
    cout << "Brand: "; cin >> brand;
    cout << "Model: "; cin >> model;
    cout << "Engine volume (cc): "; cin >> engineVolume;
    cout << "Power (hp): "; cin >> enginePower;
    cout << "Terrain type (road/offroad): "; cin >> terrainType;
}

void Motorcycle::saveToFile(ofstream& out) const {
    out << 2 << endl;
    Vehicle::saveToFile(out);
    out << engineVolume << endl;
    out << enginePower << endl;
    out << terrainType << endl;
}

void Motorcycle::loadFromFile(ifstream& in) {
    Vehicle::loadFromFile(in);
    in >> engineVolume >> enginePower;
    in.ignore();
    getline(in, terrainType);
}