/*
Define a class Employee that stores information about:

Name (character array with a maximum of 20 characters)
ID (character array with a maximum of 14 characters)
Salary (float)
For the class, define a copy constructor, default constructor, and a parameterized constructor.

Define a class Department that stores information about:

Department ID (int)
Name (character array with a maximum of 50 characters)
Array of 3 employees (objects of the class Employee)
In the Department class, add a method that checks if there are two employees with the same ID number.

Note: The translation assumes that "поле од 3 вработени" means an array of 3 
employees in the context of the Department class. If it means something different, please provide clarification.
*/

#include <iostream>
#include <cstring>

using namespace std;

class Employee {
private:
    char name[20];
    char id[15];
    float salary;
public:
    Employee() {}
    Employee(char *name, char *id, float salary){
        strcpy(this->name, name);
        strcpy(this->id, id);
        this->salary = salary;
    }
    Employee(const Employee& e) {
        strcpy(this->name, e.name);
        strcpy(this->id, e.id);
        this->salary = e.salary;
    }

    const char *getName(){
        return name;
    }

    char *getId(){
        return id;
    }

    float getSalary() const {
        return salary;
    }

    void setSalary(float salary) {
        Employee::salary = salary;
    }

    void setID(char *id) {
        strcpy(this->id, id);
    }
};

class Department {
private:
    int id_department;
    char name[50];
    Employee employees[3];
public:
    Department() {}

    Department(int idDepartment, char *name, Employee *employees) {
        strcpy(this->name, name);
        this->id_department = idDepartment;
        for (int i = 0; i < 3; i++)
            this->employees[i] = employees[i];
    }
    Department(Department& d) {
        strcpy(this->name, d.name);
        this->id_department = d.id_department;
        for (int i = 0; i < 3; i++)
            this->employees[i] = d.employees[i];
    }

    int getId() {
        return id_department;
    }

    void setIdDepartment(int idDepartment) {
        id_department = idDepartment;
    }

    char *getName(){
        return name;
    }

    Employee *getEmployees(){
        return employees;
    }

    bool hasDuplicateID() {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) {
                if(i==j)
                    continue;
                if (strcmp(employees[i].getId(), employees[j].getId()) == 0)
                    return true;
            }
        return false;
    }
};

//ne smee da se menuva main funkcijata
int main()
{
    char ID[14], ime[20], name[50];
    int broj, n, numEmployees,id1;
    float salary;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ID >> ime >> salary;
        Employee p1(ime, ID, salary);
        cin >> ID >> ime >> salary;
        Employee p2(ime, ID, salary);
        cin >> ID >> ime >> salary;
        Employee p3(ime, ID, salary);
        cin >> id1 >> name;
        Employee p[3];
        p[0] = p1; p[1] = p2; p[2] = p3;
        Department d(id1, name, p);
        cout << "Department " << d.getId() << ":" << endl;
        if(d.hasDuplicateID() == true)
            cout << "Postojat vraboteni so ist ID" << endl;
        else
            cout << "Ne postojat vraboteni so ist ID" << endl;
    }
    return 0;
}
