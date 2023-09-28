#include <string>
#ifndef BEV_H
#define BEV_H

class Beverage {
    public:
        Beverage(std::string name);
        Beverage(std::string name, float cost);
        std::string getName();
        float getCost();
        std::string toString();
        void applyInflation(float inflation);
    protected:
        std::string name;
        float cost;
};
#endif