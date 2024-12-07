#include <vector>
#include <algorithm>
#include "Moto.cpp"
#include "Car.cpp"
#include <memory>

class Garage {
private:
    vector<unique_ptr<Car>> cars;
    vector<unique_ptr<Moto>> motos;

public:
    void addCar(unique_ptr<Car> car) {
        cars.push_back(move(car));
    }

    void addMoto(unique_ptr<Moto> moto) {
        motos.push_back(move(moto));
    }

    void deleteCar(size_t index) {
        if (index < cars.size()) {
            cars.erase(cars.begin() + index);
        }
    }

    void deleteMoto(size_t index) {
        if (index < motos.size()) {
            motos.erase(motos.begin() + index);
        }
    }

    void displayCars() const {
        if (cars.empty()) {
            cout << "No cars in the garage." << endl;
            return;
        }
        for (const auto& car : cars) {
            car->displayInfo();
            cout << endl;
        }
    }

    void displayMotos() const {
        if (motos.empty()) {
            cout << "No motorcycles in the garage." << endl;
            return;
        }
        for (const auto& moto : motos) {
            moto->displayInfo();
            cout << endl;
        }
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        size_t carCount = cars.size();
        size_t motoCount = motos.size();

        file << carCount << " " << motoCount << endl;

        for (const auto& car : cars) {
            file << car->getBrand() << " " 
                 << car->getYear() << " " 
                 << car->getDoors() << endl;
        }

        for (const auto& moto : motos) {
            file << moto->getBrand() << " " 
                 << moto->getYear() << " " 
                 << (moto->getSidecar() ? "1" : "0") << endl;
        }
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        cars.clear();
        motos.clear();

        size_t carCount, motoCount;
        file >> carCount >> motoCount;

        for (size_t i = 0; i < carCount; ++i) {
            string brand, model;
            int year, doors;
            file >> brand >> year >> doors;
            auto car = make_unique<Car>(brand, "", year, doors);
            cars.push_back(move(car));
        }

        for (size_t i = 0; i < motoCount; ++i) {
            string brand, model;
            int year;
            bool sidecar;
            file >> brand >> year >> sidecar;
            auto moto = make_unique<Moto>(brand, "", year, sidecar);
            motos.push_back(move(moto));
        }
    }

    void sortCarsByYear() {
        sort(cars.begin(), cars.end(), 
            [](const unique_ptr<Car>& a, const unique_ptr<Car>& b) {
                return a->getYear() < b->getYear();
            });
    }

    void sortMotosByYear() {
        sort(motos.begin(), motos.end(), 
            [](const unique_ptr<Moto>& a, const unique_ptr<Moto>& b) {
                return a->getYear() < b->getYear();
            });
    }

    void editCar(size_t index, const string& brand, const string& model, int year, int doors) {
        if (index < cars.size()) {
            *cars[index] = Car(brand, model, year, doors);
        }
    }

    void editMoto(size_t index, const string& brand, const string& model, int year, bool sidecar) {
        if (index < motos.size()) {
            *motos[index] = Moto(brand, model, year, sidecar);
        }
    }

    void searchCarByBrand(const string& brandToSearch) {
        for (const auto& car : cars) {
            if (car->getBrand() == brandToSearch) {
                car->displayInfo();
                cout << endl;
            }
        }
    }

    void searchMotoByBrand(const string& brandToSearch) {
        for (const auto& moto : motos) {
            if (moto->getBrand() == brandToSearch) {
                moto->displayInfo();
                cout << endl;
            }
        }
    }
};
