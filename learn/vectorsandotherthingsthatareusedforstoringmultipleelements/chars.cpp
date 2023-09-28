#include <iostream>
// no not the pixar movie


int main(){
    const char* str1 = "this is an immutable char pointer string";
    std::cout << str1 << std::endl;

    char str2[] = "this is a mutable char array string";
    str2[2] = 'a';
    str2[3] = 't';
    std::cout << str2 << std::endl;

    char str3[50];
    // prints different things each time
    // interesting behaviour
    std::cout << str3 << std::endl;

    return 0;
}