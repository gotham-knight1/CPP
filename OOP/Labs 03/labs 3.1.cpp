/*
To create a class `MobilePhone` that stores information about a mobile phone:

- Model (character array not longer than 20 characters)
- Model number (integer)
- Release year (integer)

Define the following in the class:

- Default constructor
- Parameterized constructor
- Copy constructor
- Destructor
- Getter methods if necessary
- A function for printing information in the format 
  "(model) (model number) release year: (release year)"

Then, define a class `Owner` to store the following information:

- First name (character array not longer than 20 characters)
- Last name (character array not longer than 20 characters)
- Mobile phone (object of class `MobilePhone`)

Create the following in the class:

- Default constructor
- Parameterized constructor
- Destructor
- Getter methods if necessary
- A function for printing information in the format "(first name) (last name) 
  has a mobile phone:\n(information about mobile phone)"

Note: Do not modify the main function.
*/

#include <iostream>
#include <cstring>

using namespace std;

//YOUR CODE HERE
class MobilePhone {
private:
    char name[20];
    int model_num;
    int year_commision;
public:
    MobilePhone() {}
    MobilePhone(char *name, int model_num, int year_commision){
        strcpy(this->name, name);
        this->model_num = model_num;
        this->year_commision = year_commision;
    }
    MobilePhone(const MobilePhone& p){
        strcpy(this->name, p.name);
        this->model_num = p.model_num;
        this->year_commision = p.year_commision;
    }
    ~MobilePhone() {}

    void setName(char *name) {
        strcpy(this->name, name);
    }

    char *getName() {
        return name;
    }

    int getModelNum() const {
        return model_num;
    }

    void setModelNum(int modelNum) {
        this->model_num = modelNum;
    }

    int getYearCommision() const {
        return year_commision;
    }

    void setYearCommision(int yearCommision) {
        this->year_commision = yearCommision;
    }
    void print() {
        cout << name << " " << model_num << " release year: " << year_commision << endl;
    }
};

class Owner {
private:
    char name[20];
    char surname[20];
    MobilePhone phone;
public:
    Owner() {}
    Owner(char *name, char *surname, MobilePhone& phone) {
        strcpy(this->name, name);
        strcpy(this->surname, surname);
        this->phone = phone;
    }
    Owner(Owner &o) {
        strcpy(this->name, o.name);
        strcpy(this->surname, o.surname);
        this->phone = o.phone;
    }
    ~Owner() {}

    const char *getName() const {
        return name;
    }

    const char *getSurname() const {
        return surname;
    }

    const MobilePhone &getPhone() const {
        return phone;
    }

    void setPhone(const MobilePhone &phone) {
        Owner::phone = phone;
    }
    void print() {
        cout << name << " " << surname << " has a mobile phone: " << endl;
        phone.print();
    }
};


//DO NOT CHANGE THE MAIN FUNCTION
int main() {
    char model[20];
    int modelNumber;
    int year;
    char name[20];
    char surname[20];

    int testCase;

    cin>>testCase;

    cin>>model;
    cin>>modelNumber;
    cin>>year;
    cin>>name;
    cin>>surname;

    if(testCase==1){
        MobilePhone mobilePhone(model,modelNumber,year);

        Owner owner(name,surname,mobilePhone);
        owner.print();
    }
    if(testCase==2){
        MobilePhone mobilePhone(MobilePhone(model,modelNumber,year));

        Owner owner(name,surname,mobilePhone);
        owner.print();
    }

}
