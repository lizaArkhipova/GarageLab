#include "Garage.h"

void showMenu() {
    cout << "\nGARAGE MENU" << endl;
    cout << "1. Add car" << endl;
    cout << "2. Add motorcycle" << endl;
    cout << "3. Add bus" << endl;
    cout << "4. Remove vehicle" << endl;
    cout << "5. Show all" << endl;
    cout << "6. Show one" << endl;
    cout << "7. Edit vehicle" << endl;
    cout << "8. Save to file" << endl;
    cout << "9. Load from file" << endl;
    cout << "0. Exit" << endl;
    cout << ".............." << endl;
    cout << "Choice: ";
}

int main() {
    Garage garage;
    int choice;

    try {
        do {
            showMenu();
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                throw runtime_error("Invalid input");
            }

            switch (choice) {
            case 1: {
                Car* car = new Car();
                car->input();
                garage.addVehicle(car);
                break;
            }
            case 2: {
                Motorcycle* moto = new Motorcycle();
                moto->input();
                garage.addVehicle(moto);
                break;
            }
            case 3: {
                Bus* bus = new Bus();
                bus->input();
                garage.addVehicle(bus);
                break;
            }
            case 4: {
                cout << "Total records: " << garage.getCount() << endl;
                cout << "Number to remove: ";
                int idx;
                cin >> idx;
                garage.removeVehicle(idx - 1);
                break;
            }
            case 5:
                garage.displayAll();
                break;
            case 6: {
                cout << "Number (1.." << garage.getCount() << "): ";
                int idx;
                cin >> idx;
                garage.displayVehicle(idx - 1);
                break;
            }
            case 7: {
                cout << "Number (1.." << garage.getCount() << "): ";
                int idx;
                cin >> idx;
                garage.editVehicle(idx - 1);
                break;
            }
            case 8: {
                string filename;
                cout << "Filename: ";
                cin >> filename;
                garage.saveToFile(filename);
                break;
            }
            case 9: {
                string filename;
                cout << "Filename: ";
                cin >> filename;
                garage.loadFromFile(filename);
                break;
            }
            case 0:
                cout << "Exit." << endl;
                break;
            default:
                throw runtime_error("Invalid menu item");
            }
        } while (choice != 0);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}