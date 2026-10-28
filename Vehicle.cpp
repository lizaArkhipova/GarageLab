    #include "Vehicle.h"

    Vehicle::Vehicle() : brand("Unknown"), model("Unknown") { //инициализация 
        // конструктор без параметров
    }
     
    Vehicle::Vehicle(const string& brand, const string& model) //конструктор копирования
        : brand(brand), model(model) { //: это список инициализации. быстрее работает 
        cout << "[Vehicle] Parameterized constructor: " << brand << " " << model << endl;
    }

    Vehicle::Vehicle(const Vehicle& other)  //деструктор 
        : brand(other.brand), model(other.model) {
        cout << "[Vehicle] Copy constructor: " << brand << " " << model << endl;
    }

    Vehicle::~Vehicle() {
        cout << "[Vehicle] Destructor: " << brand << " " << model << endl;
    }

    Vehicle& Vehicle::operator=(const Vehicle& other) { //перегрузка оператора сприсваивания
        if (this != &other) { //проверка чтобы не присваивать объект самому себе
            brand = other.brand;
            model = other.model;
            cout << "[Vehicle] operator=: " << brand << " " << model << endl;
        }
        return *this;
    }

    string Vehicle::getBrand() const { return brand; } //геттеры
    string Vehicle::getModel() const { return model; } //сеттеры
    void Vehicle::setBrand(const string& b) { brand = b; }
    void Vehicle::setModel(const string& m) { model = m; }

    void Vehicle::saveToFile(ofstream& out) const { //запись данных в файл
        out << brand << endl;
        out << model << endl;
    }

    void Vehicle::loadFromFile(ifstream& in) { //чтение данных из файла
        getline(in, brand);  //читает всю строку целиком
        getline(in, model);
    }