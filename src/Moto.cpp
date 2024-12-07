#include "Vehicle.cpp"

class Moto : public Vehicle {
private:
    bool hasSidecar;

public:
    Moto(const string& b = "", const string& m = "", int y = 0, bool sidecar = false) 
        : Vehicle(b, m, y), hasSidecar(sidecar) {}

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << (hasSidecar ? " (with sidecar)" : " (no sidecar)");
    }

    bool getSidecar() const { return hasSidecar; }
};