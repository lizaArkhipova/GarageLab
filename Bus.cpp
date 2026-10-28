#include "Bus.h"

Bus::Bus() : Vehicle(), seatedPlaces(0), totalPlaces(0), finalDestination("Unknown") {
    cout << "[Bus] Default constructor: " << endl;
}

Bus::Bus(const string& brand, const string& model, int seatedPlaces,
    int totalPlaces, const string& finalDestination)
    : Vehicle(brand, model), seatedPlaces(seatedPlaces),
    totalPlaces(totalPlaces), finalDestination(finalDestination) {
    cout << "[Bus] Parameterized constructor: " << brand << " " << model << endl;
}

Bus::Bus(const Bus& other)
    : Vehicle(other), seatedPlaces(other.seatedPlaces),
    totalPlaces(other.totalPlaces), finalDestination(other.finalDestination) {
    cout << "[Bus] Copy constructor: " << brand << " " << model << endl;
}

Bus::~Bus() {
    cout << "[Bus] Destructor: " << brand << " " << model << endl;
}

Bus& Bus::operator=(const Bus& other) {
    if (this != &other) {
        Vehicle::operator=(other);
        seatedPlaces = other.seatedPlaces;
        totalPlaces = other.totalPlaces;
        finalDestination = other.finalDestination;
        cout << "[Bus] operator=: " << brand << " " << model << endl;
    }
    return *this;
}

int Bus::getSeatedPlaces() const { return seatedPlaces; }
int Bus::getTotalPlaces() const { return totalPlaces; }
string Bus::getFinalDestination() const { return finalDestination; }
void Bus::setSeatedPlaces(int s) { seatedPlaces = s; }
void Bus::setTotalPlaces(int t) { totalPlaces = t; }
void Bus::setFinalDestination(const string& d) { finalDestination = d; }

void Bus::display() const {
    cout << "   Bus   " << endl;
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Seated places: " << seatedPlaces << endl;
    cout << "Total places: " << totalPlaces << endl;
    cout << "Final destination: " << finalDestination << endl;
}

void Bus::input() {
    cout << "Enter bus data:" << endl;
    cout << "Brand: "; cin >> brand;
    cout << "Model: "; cin >> model;
    cout << "Seated places: "; cin >> seatedPlaces;
    cout << "Total places: "; cin >> totalPlaces;
    cout << "Final destination: "; cin >> finalDestination;
}

void Bus::saveToFile(ofstream& out) const {
    out << 3 << endl;
    Vehicle::saveToFile(out);
    out << seatedPlaces << endl;
    out << totalPlaces << endl;
    out << finalDestination << endl;
}

void Bus::loadFromFile(ifstream& in) {
    Vehicle::loadFromFile(in);
    in >> seatedPlaces >> totalPlaces;
    in.ignore();
    getline(in, finalDestination);
}