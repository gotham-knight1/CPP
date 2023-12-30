#include <iostream>
#include <cstring>
using namespace std;

class Vehicle {
protected:
    char model[40];
    double enginePower, maxSpeed, fuelEfficiency;
public:
    Vehicle(char *model = "", double enginePower = 0, double maxSpeed = 0, double fuelEfficiency = 0) : enginePower(enginePower), maxSpeed(maxSpeed), fuelEfficiency(fuelEfficiency) {
        strcpy(this->model, model);
    }

    virtual void displayInfo() {
        cout << "Engine power: " << enginePower << endl;
        cout << "Maximum speed: " << maxSpeed << endl;
        cout << "Fuel efficiency: " << fuelEfficiency << endl;
    }

    virtual float power() = 0;
};

class LuxuryVehicle : virtual public Vehicle {
private:
    int numOfSeets;
public:
    LuxuryVehicle(char *model = "", double enginePower = 0, double maxSpeed = 0, double fuelEfficiency = 0, int numOfSeets = 0) : Vehicle(model, enginePower, maxSpeed, fuelEfficiency), numOfSeets(numOfSeets) {}

    void displayInfo() {
        cout << "LuxuryVehicle: " << model << endl;
        cout << "Number of seats: " << numOfSeets << endl;
        Vehicle::displayInfo();
        cout << "Power: " << power() << endl;
    }
    float power() {
        return (0.2 * enginePower * numOfSeets) + (0.55 * maxSpeed * numOfSeets) + (0.25 * fuelEfficiency * numOfSeets);
    }
};

class SportsVehicle : virtual public Vehicle {
private:
    bool isConvertible;
public:
    SportsVehicle(char *model = "", double enginePower = 0, double maxSpeed = 0, double fuelEfficiency = 0, bool isConvertible = false) : Vehicle(model, enginePower, maxSpeed, fuelEfficiency), isConvertible(isConvertible) {}

    void displayInfo(){
        cout << "SportsVehicle: " << model << endl;
        (isConvertible) ? cout << "Convertible: Yes" << endl : cout << "Convertible: No" << endl;
        Vehicle::displayInfo();
        cout << "Power: " << power();
    }

    float power(){
        return enginePower + maxSpeed + fuelEfficiency;
    }
};

class LuxurySportsVehicle : public LuxuryVehicle, public SportsVehicle {
public:
    LuxurySportsVehicle(char *model = "", double enginePower = 0, double maxSpeed = 0, double fuelEfficiency = 0, int numOfSeets = 0, bool isConvertible = false) : LuxuryVehicle(model, enginePower, maxSpeed, fuelEfficiency, numOfSeets),
                                                                                                                                                                    SportsVehicle(model, enginePower, maxSpeed, fuelEfficiency, isConvertible),
                                                                                                                                                                    Vehicle(model, enginePower, maxSpeed, fuelEfficiency){}
    void displayInfo(){
        cout << "LuxurySportsVehicle: " << model << endl;
        Vehicle::displayInfo();
        cout << "Power: " << power();
    }

    float power() {
        return (LuxuryVehicle::power() + SportsVehicle::power()) / 2;
    }
};

Vehicle* mostPowerfulLuxuryVehicle(Vehicle** vehicles, int n) {
    LuxuryVehicle *mostPowerful = nullptr;

    for (int i = 0; i < n; i++) {
        LuxuryVehicle* luxVehicle = dynamic_cast<LuxuryVehicle*>(vehicles[i]);
        if(luxVehicle && (mostPowerful == nullptr || luxVehicle->power() > mostPowerful->power()))
            mostPowerful = luxVehicle;
    }
    return mostPowerful;
}

int main() {
    char model[50];
    double enginePower;
    double maximumSpeed;
    double fuelEfficiency;
    int numberOfSeats;
    bool isConvertible;
    int n;
    int choice;

    cin >> choice;
    if (choice == 1) {
        cin >> model;
        LuxurySportsVehicle luxurySportsVehicle(model, 740, 355, 13, 2, false);
        luxurySportsVehicle.displayInfo();
    }
    else {
        cin >> n;

        Vehicle** v = new Vehicle*[n];
        for (int i = 0; i < n; i++) {
            cin >> choice;
            if (choice == 1) {
                cin >> model >> enginePower >> maximumSpeed >> fuelEfficiency >> numberOfSeats;
                v[i] = new LuxuryVehicle(model, enginePower, maximumSpeed, fuelEfficiency, numberOfSeats);
            }
            else {
                cin >> model >> enginePower >> maximumSpeed >> fuelEfficiency >> isConvertible;
                v[i] = new SportsVehicle(model, enginePower, maximumSpeed, fuelEfficiency, isConvertible);
            }
        }

        mostPowerfulLuxuryVehicle(v, n)->displayInfo();
    }

    return 0;
}
