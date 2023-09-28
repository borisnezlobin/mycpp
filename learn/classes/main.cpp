#include "beverage.h"
#include "alcoholic.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv){
    Beverage water("Tap Water");
    Beverage bottled_water("Bottled Water", 3.0);
    Alcoholic vodka("Vodka", 98, 50.0); // idk man

    cout << water.toString() << endl;
    cout << vodka.toString() << endl;
    cout << bottled_water.toString() << endl;
    bottled_water.applyInflation(10);
    cout << bottled_water.toString() << endl;

    return 0;
}