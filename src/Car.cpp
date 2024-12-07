#include "Vehicle.cpp"

class Car : public Vehicle {
private:
    int doors;

public:
    Car(const string& b = "", const string& m = "", int y = 0, int d = 4) 
        : Vehicle(b, m, y), doors(d) {}

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << " (" << doors << " doors)";
    }

    int getDoors() const { return doors; }
};