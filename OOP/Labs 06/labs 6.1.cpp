/*
As a successful student at the Faculty of Computer Science and Engineering (FINKI), you have been invited to work on the improvement of the IKnow system. As part of the system, a new component responsible for handling disciplinary measures needs to be added. As a member of the software development team, you will need to implement the `DisciplinaryAction` class, which will store the following information:

- Student's name (dynamically allocated array of characters)
- Student's index (int)
- Reason for the disciplinary action (dynamically allocated array of characters)
- The number of sessions the student is not allowed to attend (int)

The class should have the following methods and constructors:

- Default constructor
- Copy constructor
- Constructor with arguments
- Destructor
- Set and Get methods for the index
- Operator =
- Operator << for printing information about the student
- Operator ++ to increase the number of sessions the student is penalized (in prefix notation)
- Operator >= to compare disciplinary actions based on the number of sessions the student is penalized

The operator << should print according to the following format:
```
Student: [Name]
Student's index: [Index]
Reason: [Reason]
Sessions: [Sessions]
```

Where the values in [] should be replaced with the values in the class!

!!! DO NOT MAKE CHANGES TO THE MAIN() FUNCTION !!!
*/

#include <iostream>
#include <cstring>

using namespace std;

#include <iostream>
#include <cstring>

using namespace std;

class DisciplinaryAction {
private:
    char* name;
    int index;
    char* reason;
    int sessions;

public:
    DisciplinaryAction() {
        name = new char[1];
        name[0] = '\0';
        reason = new char[1];
        reason[0] = '\0';
        index = 0;
        sessions = 0;
    }

    DisciplinaryAction(const DisciplinaryAction& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        reason = new char[strlen(other.reason) + 1];
        strcpy(reason, other.reason);
        index = other.index;
        sessions = other.sessions;
    }

    DisciplinaryAction(const char* name, int index, const char* reason, int sessions) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->reason = new char[strlen(reason) + 1];
        strcpy(this->reason, reason);
        this->index = index;
        this->sessions = sessions;
    }

    ~DisciplinaryAction() {
        delete[] name;
        delete[] reason;
    }

    int getIndex() const {
        return index;
    }

    void setIndex(int index) {
        this->index = index;
    }

    DisciplinaryAction& operator=(const DisciplinaryAction& other) {
        if (this != &other) {
            delete[] name;
            delete[] reason;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            reason = new char[strlen(other.reason) + 1];
            strcpy(reason, other.reason);
            index = other.index;
            sessions = other.sessions;
        }
        return *this;
    }

    DisciplinaryAction& operator++() {
        sessions++;
        return *this;
    }

    bool operator>=(const DisciplinaryAction& other) const {
        return sessions >= other.sessions;
    }

    friend ostream& operator<<(ostream& out, const DisciplinaryAction& disciplinary) {
        out << "Student: " << disciplinary.name << endl;
        out << "Student's index: " << disciplinary.index << endl;
        out << "Reason: " << disciplinary.reason << endl;
        out << "Sessions: " << disciplinary.sessions << endl;
        return out;
    }
};


/// Do NOT edit the main() function

int main() {
    int n;
    cin >> n;

    /// Testing Default constructor and equal operator
    /// Array input

    DisciplinaryAction arr[n];

    for (int i = 0; i < n; i++) {
        char name[100];
        char reason[100];
        int index;
        int sessions;

        cin >> name >> index >> reason >> sessions;

        arr[i] = DisciplinaryAction(name, index, reason, sessions);
    }

    cout << "-- Testing operator = & operator <<  --\n";
    cout << arr[0];

    /// Testing copy constructor & set index

    DisciplinaryAction merka(arr[0]);
    merka.setIndex(112233);

    cout << "\n-- Testing copy constructor & set index --\n";
    cout << "-------------\n";
    cout << "Source:\n";
    cout << "-------------\n";
    cout << arr[0];

    cout << "\n-------------\n";
    cout << "Copied and edited:\n";
    cout << "-------------\n";
    cout << merka;

    /// Testing if array is OK

    cout << "\n-- Testing if array was inputted correctly --\n";

    for (int i = 0; i < n; i++)
        cout << arr[i];


    cout << "\nTesting operator ++ and <<" << endl;
    for (int i = 0; i < n; i++)
        cout << (++arr[i]);


    cout << "\nTesting operator >=" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << i << " " << ((arr[i] >= arr[j]) ? ">= " : "< ") << j << endl;
            }
        }
    }

    return 0;
}
