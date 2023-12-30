/*
To define a class `Circle` in which information is stored about:

- Name (character array with a maximum of 100 characters) - name of the circle
- Radius (decimal number)
- x (decimal number) - x-coordinate
- y (decimal number) - y-coordinate

Define the following methods in the class:

- `print()`: Prints in the format: Circle {name} with radius {radius} and center ({x}, {y})

Next, define a class `Canvas` in which information is stored about:

- Name (character array with a maximum of 100 characters) - name of the canvas
- Circles (array of circles)
- numOfCircles (integer) - the number of circles in the canvas

Define the following methods in the class:

- `print()`: Prints in the format: Canvas {name} with {num_of_circles} circles: // Prints all circles in the canvas

All variables inside the classes should be private. Accordingly, define within the classes:

- Constructor (both default and with parameters)
- Destructor
- Set methods
- Get methods
- Copy constructor

Function outside of the class:

void findCanvasWithLargestCircles(Canvas *canvases, int numCanvases);

This function prints the canvas whose circles have the largest area. Do not modify the main function.
*/

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Circle {
private:
    char name[100];
    double radius;
    double x;
    double y;

public:
    // Default constructor
    Circle() {
        name[0] = '\0';
        radius = 0.0;
        x = 0.0;
        y = 0.0;
    }

    Circle(const char* n, double r, double cx, double cy) : radius(r), x(cx), y(cy) {
        strcpy(name, n);
    }

    // Getter and setter for name
    const char* getName() const {
        return name;
    }

    void setName(const char* newName) {
        std::strncpy(name, newName, 100);
        name[99] = '\0';
    }

    // Getter and setter for radius
    double getRadius() const {
        return radius;
    }

    void setRadius(double newRadius) {
        radius = newRadius;
    }

    // Getter and setter for x
    double getX() const {
        return x;
    }

    void setX(double newX) {
        x = newX;
    }

    // Getter and setter for y
    double getY() const {
        return y;
    }

    void setY(double newY) {
        y = newY;
    }

    // Print method
    void print() const {
        std::cout << "Circle " << name << " with radius " << radius << " and center (" << x << ", " << y << ")" << std::endl;
    }

    // Destructor
    ~Circle() {
    }

    // Copy constructor
    Circle(const Circle& other) {
        std::strncpy(name, other.name, 100);
        radius = other.radius;
        x = other.x;
        y = other.y;
    }
};

class Canvas {
private:
    char name[100];
    Circle circles[100];
    int numCircles;

public:
    // Default constructor
    Canvas() {
        name[0] = '\0';
        numCircles = 0;
    }

    // Getter and setter for name
    const char* getName() const {
        return name;
    }

    void setName(const char* newName) {
        std::strncpy(name, newName, 100);
        name[99] = '\0';
    }

    void setNumCircles(int numCircles) {
        Canvas::numCircles = numCircles;
    }

    // Getter for numCircles
    int getNumCircles() const {
        return numCircles;
    }

    // Method to add a new circle to the canvas
    void addCircle(const Circle& newCircle) {
        if (numCircles < 100) {
            circles[numCircles] = newCircle;
            numCircles++;
        }
    }

    // Print method
    void print() const {
        std::cout << "Canvas " << name << " with " << numCircles << " circles:" << std::endl;
        for (int i = 0; i < numCircles; i++) {
            circles[i].print();
        }
    }

    // Destructor
    ~Canvas() {
    }

    // Copy constructor
    Canvas(const Canvas& other) {
        std::strncpy(name, other.name, 100);
        name[99] = '\0';
        numCircles = other.numCircles;
        for (int i = 0; i < numCircles; i++) {
            circles[i] = other.circles[i];
        }
    }

    Circle& getCircle(int i) {
        return circles[i];
    }
};

void findCanvasWithLargestCircles(Canvas *canvases, int numCanvases) {
    double maxArea = 0;
    int maxCanvasIndex = -1;

    // Find canvas with circles that have the largest total area
    for (int i = 0; i < numCanvases; i++) {
        double totalArea = 0;
        for (int j = 0; j < canvases[i].getNumCircles(); j++) {
            totalArea += M_PI * pow(canvases[i].getCircle(j).getRadius(), 2);
        }
        if (totalArea > maxArea) {
            maxArea = totalArea;
            maxCanvasIndex = i;
        }
    }

    canvases[maxCanvasIndex].print();
}


int main() {
    // Read in number of canvases
    int numCanvases;
    cin >> numCanvases;

    // Create array of canvases
    Canvas canvases[numCanvases];


    // Read in data for each canvas and its circles
    for (int i = 0; i < numCanvases; i++) {
        char name[100];
        // Read in canvas name
        cin >> name;
        canvases[i].setName(name);

        // Read in number of circles for current canvas
        int numCircles;
        cin >> numCircles;

        // Set number of circles for current canvas
        canvases[i].setNumCircles(numCircles);

        // Read in data for each circle for current canvas
        for (int j = 0; j < numCircles; j++) {
            // Read in circle name
            cin >> name;
            canvases[i].getCircle(j).setName(name);

            // Read in circle radius
            double radius;
            cin >> radius;
            canvases[i].getCircle(j).setRadius(radius);

            // Read in circle center coordinates
            double x, y;
            cin >> x >> y;
            canvases[i].getCircle(j).setX(x);
            canvases[i].getCircle(j).setY(y);
        }
    }

    cout<<"Test copy constructors"<<endl;
    Canvas canvasCopy = Canvas(canvases[0]);
    canvasCopy.print();
    cout<<"Test function"<<endl;
    findCanvasWithLargestCircles(canvases, numCanvases);

    return 0;
}
