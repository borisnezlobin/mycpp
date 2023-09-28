#include "beverage.h"

// like beverage, not person
// what else do I call it
class Alcoholic: public Beverage {
    public:
        Alcoholic(std::string name, float proof, float price);
        float getProof();
        std::string toString();
    private:
        float proof;
};