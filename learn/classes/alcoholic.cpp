#include "alcoholic.h"
#include <string>
using namespace std;

Alcoholic::Alcoholic(string name, float proof, float price):Beverage(name, price){
    this->name = name;
    this->proof = proof;
    this->cost = price;
}

float Alcoholic::getProof(){
    return this->proof;
}

string Alcoholic::toString(){
    // it's not that I don't know English, it's that I have no clue how to represent
    // { proof: double, name: string, cost: double } in anything other than json
    // average programmer experience
    return std::to_string(getProof()) + "-proof drink " + getName() + " at " + std::to_string(this->cost);
}