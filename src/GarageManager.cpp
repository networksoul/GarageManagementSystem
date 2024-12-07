#include "Garage.cpp"
#include <memory>
#include <limits>

class GarageManager {
private:
    Garage garage;

public:
    void displayMenu() {
        while (true) {
            cout << "\n--- Garage Management System ---" << endl;
            cout << "1. Add Car" << endl;
            cout << "2. Add Motorcycle" << endl;
            cout << "3. Display Cars" << endl;
            cout << "4. Display Motorcycles" << endl;
            cout << "5. Delete Car" << endl;
            cout << "6. Delete Motorcycle" << endl;
            cout << "7. Edit Car" << endl;
            cout << "8. Edit Motorcycle" << endl;
            cout << "9. Search Car by Brand" << endl;
            cout << "10. Search Motorcycle by Brand" << endl;
            cout << "11. Sort Cars by Year" << endl;
            cout << "12. Sort Motorcycles by Year" << endl;
            cout << "13. Save to File" << endl;
            cout << "14. Load from File" << endl;
            cout << "15. Exit" << endl;
            cout << "Enter your choice: ";

            int choice;
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice) {
                case 1: addCar(); break;
                case 2: addMoto(); break;
                case 3: garage.displayCars(); break;
                case 4: garage.displayMotos(); break;
                case 5: deleteCar(); break;
                case 6: deleteMoto(); break;
                case 7: editCar(); break;
                case 8: editMoto(); break;
                case 9: searchCar(); break;
                case 10: searchMoto(); break;
                case 11: sortCars(); break;
                case 12: sortMotos(); break;
                case 13: saveToFile(); break;
                case 14: loadFromFile(); break;
                case 15: return;
                default: cout << "Invalid choice!" << endl;
            }
        }
    }

    void addCar() {
        try {
            string brand, model;
            int year, doors;

            cout << "Enter car brand: ";
            getline(cin, brand);
            cout << "Enter model: ";
            getline(cin, model);
            cout << "Enter year: ";
            cin >> year;
            cout << "Enter number of doors: ";
            cin >> doors;

            auto newCar = make_unique<Car>(brand, model, year, doors);
            garage.addCar(move(newCar));
            cout << "Car added successfully!" << endl;
        }
        catch (const exception& e) {
            cout << "Error adding car: " << e.what() << endl;
        }
    }

    void addMoto() {
        try {
            string brand, model;
            int year;
            bool sidecar;

            cout << "Enter motorcycle brand: ";
            getline(cin, brand);
            cout << "Enter model: ";
            getline(cin, model);
            cout << "Enter year: ";
            cin >> year;
            cout << "Has sidecar? (1/0): ";
            cin >> sidecar;

            auto newMoto = make_unique<Moto>(brand, model, year, sidecar);
            garage.addMoto(move(newMoto));
            cout << "Motorcycle added successfully!" << endl;
        }
        catch (const exception& e) {
            cout << "Error adding motorcycle: " << e.what() << endl;
        }
    }

    void deleteCar() {
        garage.displayCars();
        cout << "Enter car index to delete: ";
        size_t index;
        cin >> index;
        garage.deleteCar(index);
    }

    void deleteMoto() {
        garage.displayMotos();
        cout << "Enter motorcycle index to delete: ";
        size_t index;
        cin >> index;
        garage.deleteMoto(index);
    }

     void editCar() {
        garage.displayCars();
        cout << "Enter car index to edit: ";
        size_t index;
        cin >> index;

        string brand, model;
        int year, doors;
        cout << "Enter new brand: ";
        cin.ignore();
        getline(cin, brand);
        cout << "Enter new model: ";
        getline(cin, model);
        cout << "Enter new year: ";
        cin >> year;
        cout << "Enter new number of doors: ";
        cin >> doors;

        garage.editCar(index, brand, model, year, doors);
        cout << "Car edited successfully!" << endl;
    }

    void editMoto() {
        garage.displayMotos();
        cout << "Enter motorcycle index to edit: ";
        size_t index;
        cin >> index;

        string brand, model;
        int year;
        bool sidecar;
        cout << "Enter new brand: ";
        cin.ignore();
        getline(cin, brand);
        cout << "Enter new model: ";
        getline(cin, model);
        cout << "Enter new year: ";
        cin >> year;
        cout << "Has sidecar? (1/0): ";
        cin >> sidecar;

        garage.editMoto(index, brand, model, year, sidecar);
        cout << "Motorcycle edited successfully!" << endl;
    }

    void searchCar() {
        string brandToSearch;
        cout << "Enter car brand to search: ";
        cin.ignore();
        getline(cin, brandToSearch);
        garage.searchCarByBrand(brandToSearch);
        garage.displayCars();
    }

    void searchMoto() {
        string brandToSearch;
        cout << "Enter motorcycle brand to search: ";
        cin.ignore();
        getline(cin, brandToSearch);
        garage.searchMotoByBrand(brandToSearch);
        garage.displayMotos();
        
    }

    void sortCars() {
        garage.sortCarsByYear();
        cout << "Cars sorted by year!" << endl;
    }

    void sortMotos() {
        garage.sortMotosByYear();
        cout << "Motorcycles sorted by year!" << endl;
    }


    void saveToFile() {
        string filename;
        cout << "Enter filename to save: ";
        cin >> filename;
        garage.saveToFile(filename);
        cout << "Data saved successfully!" << endl;
    }

    void loadFromFile() {
        string filename;
        cout << "Enter filename to load: ";
        cin >> filename;
        garage.loadFromFile(filename);
        cout << "Data loaded successfully!" << endl;
    }

    void run() {
        displayMenu();
    }
};
