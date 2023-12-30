#include <iostream>
#include <cstring>

using namespace std;

class Employee {
protected:
    char name[50]; int age;
public:
    Employee(char *name = "", int age = 0) : age(age) {
        strcpy(this->name, name);
    }

    virtual void displayInfo() {
        cout << "Name: " << name << endl << "Age: " << age << endl;
    }
};

class Payable {
protected:
    double salary;
public:
    Payable(double salary = 0) : salary(salary) {}

    virtual double calculateSalary() = 0;
};

class Developer : public Employee, public Payable {
private:
    char prog_lang[50];
public:
    Developer(char *name = "", int age = 0, double salary = 0, char *prog_lang = "") : Employee(name, age), Payable(salary) {
        strcpy(this->prog_lang, prog_lang);
    }
    void displayInfo(){
        cout << "-- Developer Information --" << endl;
        Employee::displayInfo();
        cout << "Salary: $" << calculateSalary() << endl;
        cout << "Programming Language: " << prog_lang << endl;
    }
    double calculateSalary() {
        return salary * 0.9;
    }
};

class Manager : public Employee, public Payable {
private:
    int num_of_departments;
public:
    Manager(char *name = "", int age = 0, double salary = 0, int num_of_departments = 0) : Employee(name, age), Payable(salary), num_of_departments(num_of_departments)  {}

    void displayInfo(){
        cout << "-- Manager Information --" << endl;
        Employee::displayInfo();
        cout << "Salary: $" << calculateSalary() << endl;
        cout << "Number of Departments: " << num_of_departments << endl;
    }
    double calculateSalary() {
        return salary + ((salary * 0.05) * num_of_departments);
    }
};

double biggestSalary(Payable* payable[], int n) {
    Payable* maxSalaryEmployee = payable[0];

    for (int i = 1; i < n; i++) {
        if (payable[i]->calculateSalary() > maxSalaryEmployee->calculateSalary()) {
            maxSalaryEmployee = payable[i];
        }
    }

    return maxSalaryEmployee->calculateSalary();
}

int main()
{
    Payable* payable[5];
    Developer developers[5];
    Manager managers[5];
    int j=0, k=0;
    for(int i=0; i<5; i++)
    {
        char name[50];
        int age;
        double salary;
        cin>>name>>age>>salary;
        if(i%2==0)
        {
            char programmingLanguage[50];
            cin>>programmingLanguage;
            developers[j]=Developer(name, age, salary, programmingLanguage);
            developers[j].displayInfo();
            payable[i]=&developers[j];
            j++;
        }
        else {
            int numberOfDepartments;
            cin>>numberOfDepartments;
            managers[k]=Manager(name, age, salary, numberOfDepartments);
            managers[k].displayInfo();
            payable[i]=&managers[k];
            k++;
        }
    }
    cout<<endl<<"Biggest Salary: "<<biggestSalary(payable, 5);
    return 0;
}
