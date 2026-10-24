#include "Vehicle.h"

Vehicle::Vehicle() : brand("Unknown"), model("Unknown") {
    // конструктор без параметров
}

Vehicle::Vehicle(const string& brand, const string& model)
    : brand(brand), model(model) {
    cout << "[Vehicle] Parameterized constructor: " << brand << " " << model << endl;
}

Vehicle::Vehicle(const Vehicle& other)
    : brand(other.brand), model(other.model) {
    cout << "[Vehicle] Copy constructor: " << brand << " " << model << endl;
}

Vehicle::~Vehicle() {
    cout << "[Vehicle] Destructor: " << brand << " " << model << endl;
}

Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        brand = other.brand;
        model = other.model;
        cout << "[Vehicle] operator=: " << brand << " " << model << endl;
    }
    return *this;
}

string Vehicle::getBrand() const { return brand; }
string Vehicle::getModel() const { return model; }
void Vehicle::setBrand(const string& b) { brand = b; }
void Vehicle::setModel(const string& m) { model = m; }

void Vehicle::saveToFile(ofstream& out) const {
    out << brand << endl;
    out << model << endl;
}

void Vehicle::loadFromFile(ifstream& in) {
    getline(in, brand);
    getline(in, model);
}