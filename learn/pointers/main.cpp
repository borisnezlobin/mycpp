#include <iostream>

// pointers are pretty really goofy and turns out this is barely scratching the surface
// char* = string
// goofy
int main(int argv, char** argc) {
    int i = 42;
    int* j = &i;
    std::cout << "j: " + std::to_string(*j) << std::endl;
    i = 43;
    std::cout << "j: " + std::to_string(*j) << std::endl;
    int k = 44;
    j = &k;
    std::cout << "j: " + std::to_string(*j) << std::endl;
    return 0;
}