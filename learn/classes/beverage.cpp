#include "beverage.h"
#include <string>
using namespace std;

Beverage::Beverage(string name){
    this->name = name;
    this->cost = 0.0;
}

Beverage::Beverage(string name, float cost){
    this->name = name;
    this->cost = cost;
}

void Beverage::applyInflation(float inflation){
    this->cost = this->cost * (1 + (inflation / 100));
}

string Beverage::getName(){
    return this->name;
}

string Beverage::toString(){
    return "Drink " + this->getName() + " for " + std::to_string(this->cost);
}