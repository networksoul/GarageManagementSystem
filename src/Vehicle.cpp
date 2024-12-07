#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Vehicle {
protected:
    string brand;
    string model;
    int year;

public:
    Vehicle(const string& b = "", const string& m = "", int y = 0) 
        : brand(b), model(m), year(y) {}

    virtual void displayInfo() const {
        cout << year << " " << brand << " " << model;
    }

    string getBrand() const { return brand; }
    int getYear() const { return year; }
};