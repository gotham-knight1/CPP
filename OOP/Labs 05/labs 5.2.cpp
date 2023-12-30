/*
"For the needs of applications for ordering and food delivery (e.g., Cart, Click and Eat, etc.), 
it is necessary to implement a module for managing delivery persons.

Implement a class `DeliveryPerson` that will store information about:

- ID of the delivery person (array of up to 5 characters)
- Name of the delivery person (dynamically allocated array of characters)
- Location - the region where the delivery person is currently located (integer)
- Number of completed deliveries (integer, initially 0)

Implement the necessary constructors, the assignment operator, 
and methods for the class to function (10 points). Additionally, 
implement a method `void print()` for printing information about the delivery person (5 points).

Implement a class `DeliveryApp` that will store information about:

- Name of the application (array of up to 20 characters)
- List of delivery persons working for this company (dynamically allocated array of objects of the `DeliveryPerson` class, initially without elements)
- Number of delivery persons (number of elements in the array of delivery persons - integer, initially 0)

Implement the necessary constructors and methods for the class to function (5 points). Additionally, implement in the class:

- Method `void addDeliveryPerson(const DeliveryPerson &person)` - for adding a new delivery person to the application (10 points). Do not allow adding a delivery person with an already existing ID (5 points).
- Method `void assignDelivery(int restaurantArea, int customerArea)` - for assigning an order to the delivery person who is closest to the region of the restaurant `restaurantArea` from which the order needs to be picked up. When assigning an order to a delivery person, the following rules apply:

    - The space in which the application operates is divided into 10 adjacent regions. For example, if the restaurant is in region 5, first check if there is an available delivery person in that region (5), then check if there are delivery persons in the first adjacent regions (4 and 6), then in the second adjacent regions (3 and 7), and so on.
    - If there are multiple delivery persons in the region closest to the desired region, choose the delivery person who has completed the fewest deliveries so far.
    - After the order is assigned to the delivery person, their location is changed to the region where the order is being delivered (customerArea), and the number of completed deliveries for the delivery person is increased (15 points).

- Method `void print()` - for printing information about all delivery persons working for the company (format in test examples) (10 points).

Explanation for the second test example:

The application has four delivery persons: Stefan (located in 2), Vlatko (located in 3), Stojmenski (located in 8), and Tenev (located in 1).

The first order is from region 2 to 4. Stefan is 0 regions away from region 2, Vlatko is 1 region away, Stojmenski is 6 regions away, and Tenev is 1 region away. The order will be assigned to Stefan because he is the closest, and his location will be changed to 4.

The second order is from region 3 to 5. Stefan is 1 region away, Vlatko 0 regions, Stojmenski 5 regions, and Tenev 2 regions. The order will be assigned to Vlatko because he is the closest, and his location will be changed to 5.

The third order is from region 2 to 9. The closest to this order is Tenev (only 1 region away from region 2). The order will be assigned to Tenev because he is the closest, and his location will be changed to 9.

The fourth order is from region 8 to region 10. The closest to this order is Stojmenski (0 regions away from the restaurant), so he will pick up the order.

In this example, all delivery persons pick up exactly one order."
*/

#include<iostream>
#include<cstring>

using namespace std;

class DeliveryPerson {
private:
    char ID[6];
    char *name;
    int location;
    int deliveries;

    void copy(const DeliveryPerson &other) {
        this->location = other.location;
        this->deliveries = other.deliveries;
        strcpy(this->ID, other.ID);
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }

public:
    DeliveryPerson(char *id = "", char *name = "", int location = 0, int deliveries = 0) : location(location),
                                                                                           deliveries(deliveries) {
        strcpy(this->ID, id);
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    DeliveryPerson(const DeliveryPerson &other) {
        copy(other);
    }

    DeliveryPerson &operator=(const DeliveryPerson &other) {
        if (this != &other) {
            delete[] name;
            copy(other);
        }
        return *this;
    }

    ~DeliveryPerson() {
        delete[] name;
    }

    void print() {
        cout << "ID: " << ID << " Name: " << name << " Current location: " << location << " # of deliveries: "
             << deliveries << endl;
    }

    bool isSame(const DeliveryPerson &d) {
        return strcmp(this->ID, d.ID) == 0;
    }

    int distance(int area) {
        return abs(location - area);
    }

    int getDeliveries() const {
        return deliveries;
    }

    void setLocation(int location) {
        DeliveryPerson::location = location;
    }

    void setDeliveries(int deliveries) {
        DeliveryPerson::deliveries = deliveries;
    }

    void increaseDeliveries() {
        ++deliveries;
    }

    char * getName() {
        return name;
    }

    bool compare (DeliveryPerson & dp, int area){
        if (this->distance(area) < dp.distance(area)){
            return true;
        } else if (this->distance(area) == dp.distance(area)) {
            return this->deliveries < dp.deliveries;
        } else {
            return false;
        }
    }
};

class DeliveryApp {
private:
    char name[20];
    DeliveryPerson * drivers;
    int count;

    void copy(const DeliveryApp &other) {
        strcpy(this->name, other.name);
        count = other.count;
        drivers = new DeliveryPerson[count];
        for (int i = 0; i < count; i++) {
            drivers[i] = other.drivers[i];
        }
    }

public:
    DeliveryApp(char *name = "") {
        strcpy(this->name, name);
        drivers = new DeliveryPerson [0];
        count = 0;
    }

//    DeliveryApp (const DeliveryApp & other){
//        copy(other);
//    }
//
//    DeliveryApp & operator = (const DeliveryApp & other){
//        if (this!=&other){
//            delete [] drivers;
//            copy(other);
//        }
//        return *this;
//    }

    ~DeliveryApp() {
        delete[] drivers;
    }

    void print() {
        cout << name << endl;
        if (count == 0) {
            cout << "EMPTY" << endl;
        }
        for (int i = 0; i < count; ++i) {
            drivers[i].print();
        }
    }

    void addDeliveryPerson(const DeliveryPerson &driver) {
        for (int i = 0; i < count; ++i) {
            if (drivers[i].isSame(driver)) {
                return;
            }
        }

        DeliveryPerson *tmp = new DeliveryPerson[count + 1];
        for (int i = 0; i < count; ++i) {
            tmp[i] = drivers[i];
        }
        tmp[count++] = driver;
        delete[] drivers;
        drivers = tmp;
    }

    void assignDelivery(int restaurantArea, int customerArea) {
        int idx = 0;
        for (int i=1;i<count;i++){
            if (drivers[i].compare(drivers[idx], restaurantArea)){
                idx = i;
            }
        }

        drivers[idx].increaseDeliveries();
        drivers[idx].setLocation(customerArea);
    }


};

void readAppData(DeliveryApp &app) {

}

int main() {

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "CONSTRUCTOR DeliveryPerson" << endl;
        DeliveryPerson person("12345", "Stefan", 5);
        person.print();
        cout << "CONSTRUCTOR DeliveryPerson OK" << endl;
    } else if (testCase == 2) {
        cout << "COPY-CONSTRUCTOR DeliveryPerson" << endl;
        DeliveryPerson person = DeliveryPerson("12345", "Stefan", 5);
        person.print();
        cout << "COPY-CONSTRUCTOR DeliveryPerson OK" << endl;
    } else if (testCase == 3) {
        cout << "DEFAULT CONSTRUCTOR AND OPERATOR = DeliveryPerson" << endl;
        DeliveryPerson person;
        DeliveryPerson person2("12345", "Stefan", 5);
        person = person2;
        person.print();
        cout << "DEFAULT CONSTRUCTOR AND OPERATOR = DeliveryPerson OK" << endl;
    } else if (testCase == 4) {
        cout << "CONSTRUCTOR DeliveryApp" << endl;
        char appName[50];
        cin >> appName;
        DeliveryApp app(appName);
        app.print();
        cout << "CONSTRUCTOR DeliveryApp OK" << endl;
    } else if (testCase == 5) {
        cout << "DeliveryApp addDeliveryPerson test" << endl;
        char appName[50];
        cin >> appName;
        DeliveryApp app(appName);
        int n;
        cin >> n;
        char ID[6];
        char name[20];
        int location;
        for (int i = 0; i < n; i++) {
            cin >> ID >> name >> location;
            app.addDeliveryPerson(DeliveryPerson(ID, name, location));
        }
        app.print();
    } else if (testCase == 6) {
        cout << "DeliveryApp addDeliveryPerson test" << endl;
        char appName[50];
        cin >> appName;
        DeliveryApp app(appName);
        int n;
        cin >> n;
        char ID[6];
        char name[20];
        int location;
        for (int i = 0; i < n; i++) {
            cin >> ID >> name >> location;
            app.addDeliveryPerson(DeliveryPerson(ID, name, location));
        }
        cin >> n; //read assign deliveries
        for (int i = 0; i < n; i++) {
            int restaurantArea, customerArea;
            cin >> restaurantArea >> customerArea;
            app.assignDelivery(restaurantArea, customerArea);
        }
        app.print();
    }
    return 0;
}
