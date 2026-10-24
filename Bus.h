#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"

class Bus : public Vehicle {
private:
    int seatedPlaces;
    int totalPlaces;
    string finalDestination;

public:
    Bus();
    Bus(const string& brand, const string& model, int seatedPlaces,
        int totalPlaces, const string& finalDestination);
    Bus(const Bus& other);
    ~Bus() override;

    Bus& operator=(const Bus& other);

    int getSeatedPlaces() const;
    int getTotalPlaces() const;
    string getFinalDestination() const;
    void setSeatedPlaces(int s);
    void setTotalPlaces(int t);
    void setFinalDestination(const string& d);

    void display() const override;
    void input() override;

    void saveToFile(ofstream& out) const override;
    void loadFromFile(ifstream& in) override;
};

#endif