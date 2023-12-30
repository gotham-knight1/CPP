/*
For the programming language, use C.

Create a structure named Engine to store data for horsepower (int) and torque (int).

Then, create a structure named Car to store data for the manufacturer's name (char array), 
the year of manufacture (int), and the engine used (Engine).

At the beginning, input the number N indicating how many cars will be read from the input.

Create the function:

c
Copy code
void printCars(...)
This function should take the two cars with the least horsepower, and among these two, 
print the car with the greater torque.
*/

#include <stdio.h>

typedef struct Engine {
    int horsepower;
    int torque;
} Engine;

typedef struct Car {
    char car_name[20];
    int year_made;
    Engine engine;
} Car;

void printCars(Car *car, int num_of_cars) {

    int index, temp;
    int min_horsepower = 10000000;
    int max_torque = 0;

    for (int i = 0; i < num_of_cars; i++) {
        
        if (min_horsepower > car[i].engine.horsepower) {
            min_horsepower = car[i].engine.horsepower;
            temp = index;
            index = i;
        }
    }
    
    if(car[temp].engine.torque > car[index].engine.torque)
        printf("Manufacturer: %s\nHorsepower: %d\nTorque: %d", car[temp].car_name, car[temp].engine.horsepower, car[temp].engine.torque);
}

int main () {

    int num_of_cars;
    scanf("%d", &num_of_cars);

    Car car[50];

    for (int i = 0; i < num_of_cars; i++) {

        scanf("%s %d %d %d", car[i].car_name, &car[i].year_made, &car[i].engine.horsepower, &car[i].engine.torque);
    }

    printCars((Car *) car, num_of_cars);
}
