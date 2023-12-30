/*
Define a `Student` class that stores:

- `name` (dynamically allocated character array) - student's name
- `age` (integer) - student's age
- `major` (dynamically allocated character array) - student's major

Define the following constructors for the class:

- Default constructor
- Parameterized constructor
- Copy constructor

Next, define a `Classroom` class that stores:

- `students` (dynamically allocated array of `Student` objects)
- `numStudents` (integer) - number of students in the classroom
- `capacity` (integer) - capacity of the classroom

Define the following constructors for the class:

- Default constructor
- Parameterized constructor

For the `Classroom` class, define the following methods:

- `add` - adds a new student
- `remove` - removes a student with a given name
- `findMedianAge` - finds the median age of students in the given classroom

Example: For ages 2, 4, 5, 6, 7, 8, 10, the median is 6.
Example: For ages 2, 4, 5, 7, 8, 10, 12, 20, the median is (7 + 8)/2.

The ages should be in ascending order.

If necessary, create get and set methods.

All students have unique names.

Do not modify the `main` function.
*/

#include <iostream>
#include <cstring>

using namespace std;

class Student {
    private:
        char* name;
        int age;
        char* major;

    public:
        Student(){}

        Student(const char* name, int age, const char* major) {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
            this->age = age;
            this->major = new char[strlen(major) + 1];
            strcpy(this->major, major);
        }

        // Copy constructor
        Student(const Student& other) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            age = other.age;
            major = new char[strlen(other.major) + 1];
            strcpy(major, other.major);
        }

        ~Student() {
        }

        const char* getName() const {
            return name;
        }

        int getAge() const {
            return age;
        }

        const char* getMajor() const {
            return major;
        }
};


class Classroom {
private:
    Student* students;
    int numStudents;
    int capacity;

public:
    Classroom() {
        students = nullptr;
        numStudents = 0;
        capacity = 0;
    }

    Classroom(const Classroom& other) {
        numStudents = other.numStudents;
        capacity = other.capacity;

        students = new Student[capacity];
        for (int i = 0; i < numStudents; i++) {
            students[i] = other.students[i];
        }
    }


    void add(const Student& student) {
        if (numStudents == capacity) {
            int newCapacity = capacity + 5;
            Student* temp = new Student[newCapacity];

            for (int i = 0; i < numStudents; i++) {
                temp[i] = students[i];
            }

            delete[] students;
            students = temp;
            capacity = newCapacity;
        }

        students[numStudents] = student;
        numStudents++;
    }

    void remove(const char* name) {
        int index = -1;

        for (int i = 0; i < numStudents; i++) {
            if (strcmp(students[i].getName(), name) == 0) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            for (int i = index; i < numStudents - 1; i++) {
                students[i] = students[i+1];
            }

            numStudents--;
        }
    }

    void printStudents() const {
        for (int i = 0; i < numStudents; i++) {

            std::cout << students[i].getName() << " (" << students[i].getAge() << ", " << students[i].getMajor() << ")" << std::endl;
        }
        cout<<endl;
    }

    Student *getStudents() const {
        return students;
    }

    int getNumStudents() const {
        return numStudents;
    }
};

double findMedianAge(const Classroom& classroom) {
    const Student* students = classroom.getStudents();
    int numStudents = classroom.getNumStudents();

    // make a copy of the students array
    Student* copy = new Student[numStudents];
    for (int i = 0; i < numStudents; i++) {
        copy[i] = students[i];
    }

    // sort the copy by age
    for (int i = 0; i < numStudents; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (copy[i].getAge() > copy[j].getAge()) {
                Student temp = copy[i];
                copy[i] = copy[j];
                copy[j] = temp;
            }
        }
    }

    // find the median age
    int n = numStudents;
    if (n % 2 == 0) {
        return (copy[n/2-1].getAge() + copy[n/2].getAge()) / 2.0;
    } else {
        return copy[n / 2].getAge();
    }
}



int main() {
    int numClassrooms, numStudents;
    cin >> numClassrooms;
    Classroom classrooms[100];
    Student students[100];

    // Testing add method
    for (int i = 0; i < numClassrooms; i++) {
        cin >> numStudents;
        for (int j = 0; j < numStudents; j++) {
            char name[100], major[100];
            int age;
            cin >> name >> age >> major;
            Student student(name, age, major);
            classrooms[i].add(student);
            students[i*numStudents + j] = student;
        }
        cout<<"Classroom "<<i<<endl;
        classrooms[i].printStudents();
    }


    // Testing findMedianAge method
    int targetClassroom;
    cin >> targetClassroom;
    double medianAge = findMedianAge(classrooms[targetClassroom]);
    cout << "The median age in classroom " << targetClassroom << " is: " << medianAge << endl;
    cout<<"After removing the elements:"<<endl;
    // Testing remove method
    cin >> numStudents;
    for (int j = 0; j < numStudents; j++) {
        char name[100];
        cin >> name;
        for (int i = 0; i < numClassrooms; i++) {
            classrooms[i].remove(name);
        }
    }
    for (int i = 0; i < numClassrooms; i++) {
        cout<<"Classroom "<<i<<endl;
        classrooms[i].printStudents();
    }

    return 0;
}

