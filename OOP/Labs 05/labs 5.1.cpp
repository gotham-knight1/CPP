/*
In the C programming language, create a structure UmetnickoDelo to 
describe an artwork in a given gallery. The structure should contain: (5 points)

Author (character array of 100 characters)
Price (real number)
Type of artwork (integer with a value of 1 for a painting, 2 for a sculpture)
Create a structure Galerija that contains: (5 points)

Gallery name (character array of 50 characters)
Array of available artworks (array of up to 30 elements of the UmetnickoDelo structure)
Number of elements in the array (integer)
Create a global function print to print information about a given gallery in the following format: (10 points)

[Gallery name]

[Author1] [Price1] [Type1]

[Author2] [Price2] [Type2]

[Author3] [Price3] [Type3]

...

Create a function najdobra_ponuda that takes an array of variables of type 
Galerija and a variable tipNaDelo. This function should print the name of the gallery 
that offers the cheapest artwork (for a variable with a value of 1) and the name of the 
gallery that offers the cheapest sculpture (for a variable with a value of 2). 
The cheapest artwork is the artwork with the lowest price. If there are multiple 
galleries with the cheapest artwork, print the last one. (15 points)
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char avtor[100];
    float cena;
    int tip;
} UmetnickoDelo;

typedef struct {
    char ime[50];
    UmetnickoDelo umetnicki_dela[30];
    int broj_na_dela;
} Galerija;

void print(Galerija g) {
    printf("%s\n", g.ime);
    for (int i = 0; i < g.broj_na_dela; i++) {
        printf("%s %.2f %d\n", g.umetnicki_dela[i].avtor, g.umetnicki_dela[i].cena, g.umetnicki_dela[i].tip);
    }
}

void najdobra_ponuda(Galerija galerii[], int n, int tipNaDelo) {
    float min_cena = 1e9;
    char ime_na_galerija[50];
    int pronajdeno = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < galerii[i].broj_na_dela; j++) {
            if (galerii[i].umetnicki_dela[j].tip == tipNaDelo && galerii[i].umetnicki_dela[j].cena < min_cena) {
                min_cena = galerii[i].umetnicki_dela[j].cena;
                strcpy(ime_na_galerija, galerii[i].ime);
                pronajdeno = 1;
            }
        }
    }

    if (pronajdeno == 1) {
        printf("Najevtino umetnicko delo tip ");

        switch (tipNaDelo) {
            case 1:
                printf("slika"); break;
            case 2:
                printf("skulptura"); break;
        }

        printf(" go nudi galerijata: %s so cena: %.2f\n", ime_na_galerija, min_cena);
    }
    else{
        printf("Ne e pronajdeno umetnicko delo od tip ");
        switch (tipNaDelo) {
            case 1:
                printf("slika"); break;
            case 2:
                printf("skulptura"); break;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n); //broj na Galerii
    Galerija galerii[n];

    //vnesuvanje na galeriite, zaedno so raspolozlivite podatoci
    for (int i = 0; i < n; i++) {
        scanf("%s", galerii[i].ime);
        scanf("%d", &galerii[i].broj_na_dela);
        for (int j = 0; j < galerii[i].broj_na_dela; j++) {
            scanf("%s", galerii[i].umetnicki_dela[j].avtor);
            scanf("%f", &galerii[i].umetnicki_dela[j].cena);
            scanf("%d", &galerii[i].umetnicki_dela[j].tip);
        }
    }

    //pecatenje na prodazni saloni
    for (int i = 0; i < n; i++) {
        print(galerii[i]);
    }

    //povik na glavnata metoda
    int tipNaDelo;
    scanf("%d", &tipNaDelo);
    najdobra_ponuda(galerii, n, tipNaDelo);

    return 0;
}

