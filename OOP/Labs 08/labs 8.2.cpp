#include <iostream>
#include <cstring>

using namespace std;

class FoodItem {
protected:
    char *type;
    int num;
public:
    FoodItem(const char *type, int num) {
        this->type = new char[strlen(type) + 1];
        strcpy(this->type, type);
        this->num = num;
    }

    virtual ~FoodItem() {
        delete[] type;
    }

    virtual int getPrice() = 0;

    virtual int getTime() = 0;

    const char *getType() {
        return type;
    }
};

class Pizza : public FoodItem {
private:
    char *dough;
public:
    Pizza(const char *type, int num, const char *dough) : FoodItem(type, num) {
        this->dough = new char[strlen(dough) + 1];
        strcpy(this->dough, dough);
    }

    ~Pizza() {
        delete[] dough;
    }

    int getPrice() {
        if (strcmp(dough, "wholeWheat") == 0) {
            return num * 250;
        } else if (strcmp(dough, "glutenFree") == 0) {
            return num * 350;
        } else {
            return 0;
        }
    }

    int getTime() {
        return 25;
    }
};

class Steak : public FoodItem {
private:
    bool cooked;
public:
    Steak(const char *type, int num, bool cooked) : FoodItem(type, num) {
        this->cooked = cooked;
    }

    int getPrice() {
        return num * 1300;
    }

    int getTime() {
        if (cooked) {
            return 20;
        } else {
            return 15;
        }
    }
};

FoodItem *getMaxFoodItem(FoodItem *pItem[], int n) {
    FoodItem *maxItem = pItem[0];
    for (int i = 1; i < n; i++) {
        if (pItem[i]->getPrice() > maxItem->getPrice()) {
            maxItem = pItem[i];
        }
    }
    return maxItem;
}

int main() {
    FoodItem *p;
    int n;
    cin>>n;

    char type[30];
    char dough[30];
    bool cooked;
    int size;

    FoodItem *items[n];

    for (int i = 0; i <n; ++i) {
        cin>>type;
        cin>>size;


        if(strcmp(type, "pizza")==0 ) {
            cin>>dough;
            items[i] = new Pizza(type, size, dough);
        }else{
            cin>>cooked;
            items[i] = new Steak(type, size, cooked);
        }


    }

    FoodItem *it = getMaxFoodItem(items, n);
    cout<<"Type: "<<it->getType()<<endl;
    cout<<"The max price is: "<<it->getPrice()<<endl;
    cout<<"Time to cook: "<<it->getTime();
    return 0;
}
