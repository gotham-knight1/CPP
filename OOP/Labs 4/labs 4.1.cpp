/*
As a successful student at the Faculty of Computer Science and Engineering (FINKI), 
you are invited to work on the improvement of the IKnow system. As part of the system, 
a new component responsible for handling disciplinary actions needs to be added. 
As a member of the software development team, you are tasked with implementing the 
`DisciplinaryAction` class, which should store the following information:

- Student's name (dynamically allocated character array)
- Student's index (integer)
- Reason for the disciplinary action (dynamically allocated character array)

The class should have the following methods and constructors:

- Default constructor
- Copy constructor
- Parameterized constructor
- Destructor
- Set and Get methods for the index
- `void print()` method
- Overloaded assignment operator (`=`)

The `print()` method should output information in the following format:

Student: [Name]
Student's index: [Index]
Reason: [Reason]

Replace the values in [] with the actual values from the class.

Note: Do not make changes to the `main()` function.
*/

#include <iostream>
#include <cstring>

using namespace std;

class DisciplinaryAction {
private:
    char* name;
    int index;
    char* reason;

public:
    // Default constructor
    DisciplinaryAction() : name(nullptr), index(0), reason(nullptr) {}

    // Copy constructor
    DisciplinaryAction(const DisciplinaryAction& other) : name(nullptr), index(other.index), reason(nullptr) {
        setName(other.name);
        setReason(other.reason);
    }

    // Constructor with arguments
    DisciplinaryAction(const char* _name, int _index, const char* _reason) : name(nullptr), index(_index), reason(nullptr) {
        setName(_name);
        setReason(_reason);
    }

    // Destructor
    ~DisciplinaryAction() {
        delete[] name;
        delete[] reason;
    }

    // Getter and setter for index
    int getIndex() const {
        return index;
    }
    void setIndex(int _index) {
        index = _index;
    }

    // Print method
    void print() const {
        cout << "Student: " << name << endl;
        cout << "Student's index: " << index << endl;
        cout << "Reason: " << reason << endl;
    }

    // Operator =
    DisciplinaryAction& operator=(const DisciplinaryAction& other) {
        if (this != &other) {
            setName(other.name);
            setIndex(other.index);
            setReason(other.reason);
        }
        return *this;
    }

private:
    void setName(const char* _name) {
        if (name != nullptr) {
            delete[] name;
        }
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }

    void setReason(const char* _reason) {
        if (reason != nullptr) {
            delete[] reason;
        }
        reason = new char[strlen(_reason) + 1];
        strcpy(reason, _reason);
    }
};


/// Do NOT edit the main() function

int main() {
    int n;
    cin >> n;

    /// Testing Default constructor and equal operator
    /// Array input

    DisciplinaryAction arr[n];

    for(int i = 0; i < n; i++) {
        char name[100];
        char reason[100];
        int index;

        cin >> name >> index >> reason;

        arr[i] = DisciplinaryAction(name, index, reason);
    }

    cout << "-- Testing operator = & print() --\n";
    arr[0].print();

    /// Testing copy constructor & set index

    DisciplinaryAction merka(arr[0]);
    merka.setIndex(112233);

    cout << "\n-- Testing copy constructor & set index --\n";
    cout << "-------------\n";
    cout << "Source:\n";
    cout << "-------------\n";
    arr[0].print();

    cout << "\n-------------\n";
    cout << "Copied and edited:\n";
    cout << "-------------\n";
    merka.print();

    /// Testing if array is OK

    cout << "\n-- Testing if array was inputted correctly --\n";

    for(int i = 0; i < n; i++)
        arr[i].print();

    return 0;
}
