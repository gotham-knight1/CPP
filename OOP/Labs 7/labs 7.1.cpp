/*
To define the class `Square` that holds information about:

- The length of the side a of the square (double)

For the class, define:

- Default constructor
- Constructor with arguments
- Copy constructor
- `double perimeter()` that calculates the perimeter of the square
- `double area()` that calculates the area of the square
- `void print()` that prints information about the square as shown in the test examples

Implement the class `Rectangle` that inherits from the class `Square`. In this class, additional information is stored:

- The extension x of the two parallel sides of the square (double)
- The extension y of the other two parallel sides (double)
  
The rectangle now essentially has 2 sides with length a + x and 2 sides with length a + y.

For the class, define:

- Default constructor
- Constructor `Rectangle(const Square &s, double x, double y)`
- Copy constructor
- Override the three methods defined above for the `Square` class

Notes:

- If x and y are equal, then the shape is not a rectangle but a square again. In that case, `print()` is called the same as for a square.
- When overriding methods in the `Rectangle` class, there must be a call to the methods with the same names from the `Square` class.
*/

#include <iostream>

using namespace std;

class Kvadrat {
    protected:
    //TODO da se deklariraat promenlivite
    double a;

    void copy (const Kvadrat &k) {a = k.a;}
    public:
    //TODO default konstruktor
    Kvadrat() {}
    //TODO konstruktor so argumenti
    Kvadrat(double a) : a(a){}
    //TODO copy konstruktor
    Kvadrat(const Kvadrat &k) { copy(k);}
    //TODO double perimentar() {}
    double perimetar() {return a * 4;}
    //TODO double plostina() {}
    double plostina() {return a * a;}
    //TODO void pecati();
    void pecati() {
        cout << "Kvadrat so dolzina a=" << a << " ima plostina P=" << plostina() << " i perimetar L=" << perimetar() << endl;
    }
};

class Pravoagolnik : public Kvadrat { //da se vmetni nasleduvanjeto
    private:
    //deklariranje na promenlivite
    double x, y;
    public:
    //TODO default konstruktor
    Pravoagolnik() {};
    //TODO konstruktor
    //Pravoagolnik (const Kvadrat &k, double x, double y)
    Pravoagolnik(const Kvadrat &k, double x, double y) : Kvadrat(k), x(x), y(y) {}
    //TODO copy konstruktor
    Pravoagolnik(const Pravoagolnik &p) : Kvadrat(p), x(p.x), y(p.y) {}
    //TODO prepokrivanje na metodite perimetar, plostina i pecati od klasata Kvadrat
    double plostina() {return (a+x)*(a+y);}
    double perimetar() {return 2*((a+x)+(a+y));}
    void pecati() {
        if (x == y) {a = a+x; Kvadrat::pecati();}
        else cout << "Pravoagolnik so strani: " << a+x << " i " << a+y << " ima plostina P=" << plostina() << " i perimetar L=" << perimetar() << endl;
    }
};

int main() {
	int n;
    double a,x,y;
	Kvadrat * kvadrati;
	Pravoagolnik * pravoagolnici;

	cin>>n;

    kvadrati = new Kvadrat [n];
    pravoagolnici = new Pravoagolnik [n];

	for (int i=0;i<n;i++){
		cin>>a;

		kvadrati[i] = Kvadrat(a);
	}

	for (int i=0;i<n;i++){
		cin>>x>>y;

		pravoagolnici[i]=Pravoagolnik(kvadrati[i],x,y);
	}

	int testCase;
	cin>>testCase;

	if (testCase==1){
		cout<<"===Testiranje na klasata Kvadrat==="<<endl;
		for (int i=0;i<n;i++)
			kvadrati[i].pecati();
	}
	else {
		cout<<"===Testiranje na klasata Pravoagolnik==="<<endl;
		for (int i=0;i<n;i++)
			pravoagolnici[i].pecati();
	}
}
