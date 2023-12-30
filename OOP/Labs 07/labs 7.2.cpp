/*
You need to implement the `Course` class, which should contain the following information:

- Name - dynamically allocated array of characters
- Price per lecture - integer
- Rating - integer
- Number of lectures - integer

For this class, you need to create:

- Default constructor
- Constructor with parameters
- Copy constructor
- Operator =
- Destructor
- Getters and setters
- Function `getTotalPrice()` that returns the total price of the course. If the course has a rating less than 7, it has a 10% discount on the total price.
- Function `print()` that prints information about the course:

```plaintext
Course: [name]
Price: [total price]
Rating: [rating]
```

You also need to implement the `ProgrammingCourse` class, which should inherit from the `Course` class and additionally have the following information:

- Programming language - dynamically allocated array of characters
- Premium - boolean
- Difficulty level - integer

For this class, you need to create:

- Default constructor
- Constructor with parameters
- Copy constructor
- Operator =
- Destructor
- Function `getTotalPrice()` that returns the total price of the programming course. If the course is premium, it will have an additional 20% discount on the already calculated price (considering the rating accordingly).
- Operator ++ that increments the difficulty level.
- Function `print()` that prints information about the programming course:

```plaintext
Course: [name]
Price: [total price]
Rating: [rating]
Programming language: [programming language]
Difficulty level: [difficulty level]
```
*/

#include <iostream>
#include <cstring>

using namespace std;

// YOUR CODE STARTS HERE

class Course {
protected:
    char *course_name;
    int price_by_lecture, rating, num_of_lectures;

    void copy(const Course &c) {
        course_name = new char[strlen(c.course_name) + 1];
        strcpy(course_name, c.course_name);
        price_by_lecture = c.price_by_lecture;
        rating = c.rating;
        num_of_lectures = c.num_of_lectures;
    }
public:
    Course(char *course_name = "", int price_by_lecture = 0, int rating = 0, int num_of_lectures = 0) : price_by_lecture(price_by_lecture), rating(rating), num_of_lectures(num_of_lectures) {
        this->course_name = new char[strlen(course_name) + 1];
        strcpy(this->course_name, course_name);
    }

    Course(const Course &c) { copy(c);}

    Course &operator=(const Course &c) {
        if (this != &c) {
            delete [] course_name;
            copy(c);
        }
        return *this;
    }

    void setCourseName(char *courseName) {
        course_name = courseName;
    }

    void setPriceByLecture(int priceByLecture) {
        price_by_lecture = priceByLecture;
    }

    void setRating(int rating) {
        Course::rating = rating;
    }

    void setNumOfLectures(int numOfLectures) {
        num_of_lectures = numOfLectures;
    }

    char *getCourseName() const {
        return course_name;
    }

    int getPriceByLecture() const {
        return price_by_lecture;
    }

    int getRating() const {
        return rating;
    }

    int getNumOfLectures() const {
        return num_of_lectures;
    }

    int getTotalPrice() {return (rating < 7) ? (price_by_lecture * num_of_lectures) * 0.9 : (price_by_lecture * num_of_lectures);}

    void print() {
        cout << "Course: " << course_name << endl;
        cout << "Price: " << getTotalPrice() << endl;
        cout << "Rating: " << rating << endl;
    }
};

class ProgrammingCourse : public Course {
private:
    char *program_lang;
    bool isPremium;
    int difficulty_lvl;

    void copy(const ProgrammingCourse &pc) {
        program_lang = new char[strlen(pc.program_lang) + 1];
        strcpy(program_lang, pc.program_lang);
        isPremium = pc.isPremium;
        difficulty_lvl = pc.difficulty_lvl;
    }
public:
    ProgrammingCourse(char *course_name = "", int price_by_lecture = 0, int rating = 0, int num_of_lectures = 0, char *program_lang = "", bool isPremium = false, int difficulty_lvl = 0) :
            Course(course_name, price_by_lecture, rating, num_of_lectures), isPremium(isPremium), difficulty_lvl(difficulty_lvl) {
        this->program_lang = new char[strlen(program_lang) + 1];
        strcpy(this->program_lang, program_lang);
    }

    ProgrammingCourse(const Course &c, char *program_lang, bool isPremium, int difficulty_lvl) : Course(c), isPremium(isPremium), difficulty_lvl(difficulty_lvl) {
        this->program_lang = new char[strlen(program_lang) + 1];
        strcpy(this->program_lang, program_lang);
    }

    ProgrammingCourse(const ProgrammingCourse &pc) : Course(pc) {
        copy(pc);
    }

    ProgrammingCourse &operator=(const ProgrammingCourse &pc) {
        if (this!=&pc) {
            Course::operator=(pc);
            delete [] program_lang;
            copy(pc);
        }
        return *this;
    }



    int getTotalPrice() {
        int vkupnacena = Course::getTotalPrice();

        if(isPremium){
            vkupnacena = vkupnacena*0.8;
        }

        return vkupnacena;
    }

    ProgrammingCourse &operator++(){
        difficulty_lvl++;
        return *this;
    }

    void print() {
        cout << "Course: " << course_name << endl;
        cout << "Price: " << getTotalPrice() << endl;
        cout << "Rating: " << rating << endl;
        cout << "Programming language: " << program_lang << endl;
        cout << "Difficulty level: " << difficulty_lvl << endl;
    }
};


//DO NOT EDIT THE MAIN FUNCTION

int main() {

    char name[100];
    int lecturePrice;
    int rating;
    int numLectures;

    char programmingLanguage[100];
    bool isPremium;
    int difficulty;

    Course * courses = new Course[5];
    ProgrammingCourse * programmingCourses = new ProgrammingCourse[5];
    int n;
    cin >> n;

    if (n == 1) {

        cout << "COURSES:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i) {
            cin >> name >> lecturePrice >> rating >> numLectures;
            courses[i] = Course(name, lecturePrice, rating, numLectures);
            courses[i].print();
            cout<<endl;
        }
    }
    else if (n == 2) {

        for (int i=0; i < 5; ++i){
            cin >> name >> lecturePrice >> rating >> numLectures;
            cin >> programmingLanguage >> isPremium >> difficulty;
            courses[i] = Course(name, lecturePrice, rating, numLectures);
            programmingCourses[i] = ProgrammingCourse(courses[i], programmingLanguage, isPremium, difficulty);
        }

        cout << "COURSES:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i) {
            courses[i].print();
            cout<<endl;
        }


        cout << "PROGRAMMING COURSES:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i) {
            programmingCourses[i].print();
            cout<<endl;
        }

    }
    else if (n == 3) {

        for (int i=0; i < 5; ++i){
            cin >> name >> lecturePrice >> rating >> numLectures;
            cin >> programmingLanguage >> isPremium >> difficulty;
            programmingCourses[i] = ProgrammingCourse(name, lecturePrice, rating, numLectures, programmingLanguage, isPremium, difficulty);
        }
        cout << "PROGRAMMING COURSES:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i) {
            programmingCourses[i].print();
            cout<<endl;
        }

        cout << "TESTING OPERATOR ++" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i) {
            ++programmingCourses[i];
            programmingCourses[i].print();
            cout<<endl;
        }


    }

    delete [] courses;
    delete [] programmingCourses;
}
