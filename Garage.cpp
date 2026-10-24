#include "Garage.h"

Garage::Garage() : vehicles(nullptr), count(0), capacity(0) {
    cout << "[Garage] Default constructor." << endl;
}

Garage::Garage(const Garage& other) : vehicles(nullptr), count(other.count), capacity(other.capacity) {
    if (capacity > 0) {
        vehicles = new Vehicle * [capacity];
        for (int i = 0; i < capacity; i++)
            vehicles[i] = nullptr;
        for (int i = 0; i < count; i++) {
            if (dynamic_cast<Car*>(other.vehicles[i]))
                vehicles[i] = new Car(*dynamic_cast<Car*>(other.vehicles[i]));
            else if (dynamic_cast<Motorcycle*>(other.vehicles[i]))
                vehicles[i] = new Motorcycle(*dynamic_cast<Motorcycle*>(other.vehicles[i]));
            else if (dynamic_cast<Bus*>(other.vehicles[i]))
                vehicles[i] = new Bus(*dynamic_cast<Bus*>(other.vehicles[i]));
        }
    }
    cout << "[Garage] Copy constructor. count=" << count << endl;
}

Garage::~Garage() {
    for (int i = 0; i < count; i++) {
        delete vehicles[i];
        vehicles[i] = nullptr;
    }
    delete[] vehicles;
    vehicles = nullptr;
    cout << "[Garage] Destructor." << endl;
}

Garage& Garage::operator=(const Garage& other) {
    if (this != &other) {
        for (int i = 0; i < count; i++)
            delete vehicles[i];
        delete[] vehicles;

        count = other.count;
        capacity = other.capacity;
        vehicles = new Vehicle * [capacity];
        for (int i = 0; i < capacity; i++)
            vehicles[i] = nullptr;
        for (int i = 0; i < count; i++) {
            if (dynamic_cast<Car*>(other.vehicles[i]))
                vehicles[i] = new Car(*dynamic_cast<Car*>(other.vehicles[i]));
            else if (dynamic_cast<Motorcycle*>(other.vehicles[i]))
                vehicles[i] = new Motorcycle(*dynamic_cast<Motorcycle*>(other.vehicles[i]));
            else if (dynamic_cast<Bus*>(other.vehicles[i]))
                vehicles[i] = new Bus(*dynamic_cast<Bus*>(other.vehicles[i]));
        }
        cout << "[Garage] operator=. count=" << count << endl;
    }
    return *this;
}

void Garage::resize() {
    int newCapacity = (capacity == 0) ? 4 : capacity * 2;
    Vehicle** newVehicles = new Vehicle * [newCapacity];
    for (int i = 0; i < newCapacity; i++)
        newVehicles[i] = nullptr;
    for (int i = 0; i < count; i++)
        newVehicles[i] = vehicles[i];
    delete[] vehicles;
    vehicles = newVehicles;
    capacity = newCapacity;
}

void Garage::addVehicle(Vehicle* v) {
    if (count >= capacity)
        resize();
    vehicles[count] = v;
    count++;
    cout << "Vehicle added." << endl;
}

void Garage::removeVehicle(int index) {
    if (index < 0 || index >= count)
        throw out_of_range("Index out of range");
    delete vehicles[index];
    for (int i = index; i < count - 1; i++)
        vehicles[i] = vehicles[i + 1];
    count--;
    cout << "Vehicle removed." << endl;
}

void Garage::displayAll() const {
    if (count == 0) {
        cout << "Garage is empty." << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << "--- Record #" << (i + 1) << " ---" << endl;
        vehicles[i]->display();
        cout << endl;
    }
}

void Garage::displayVehicle(int index) const {
    if (index < 0 || index >= count)
        throw out_of_range("Index out of range");
    vehicles[index]->display();
}

void Garage::editVehicle(int index) {
    if (index < 0 || index >= count)
        throw out_of_range("Index out of range");
    cout << "Editing record #" << (index + 1) << ":" << endl;
    vehicles[index]->input();
}

int Garage::getCount() const { return count; }

void Garage::saveToFile(const string& filename) const {
    ofstream out(filename);
    if (!out.is_open())
        throw runtime_error("Cannot open file for writing: " + filename);

    out << count << endl;
    for (int i = 0; i < count; i++)
        vehicles[i]->saveToFile(out);

    out.close();
    cout << "Data saved to file: " << filename << endl;
}

void Garage::loadFromFile(const string& filename) {
    ifstream in(filename);
    if (!in.is_open())
        throw runtime_error("Cannot open file for reading: " + filename);

    for (int i = 0; i < count; i++)
        delete vehicles[i];
    delete[] vehicles;
    count = 0;
    capacity = 0;
    vehicles = nullptr;

    int n;
    in >> n;
    in.ignore();

    for (int i = 0; i < n; i++) {
        int type;
        in >> type;
        in.ignore();

        Vehicle* obj = nullptr;
        if (type == 1) obj = new Car();
        else if (type == 2) obj = new Motorcycle();
        else if (type == 3) obj = new Bus();
        else throw runtime_error("Unknown type in file");

        obj->loadFromFile(in);
        addVehicle(obj);
    }

    in.close();
    cout << "Data loaded from file: " << filename << endl;
}