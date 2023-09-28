#include <iostream>

int main(){
    int numbers[] = {1, 2, 3};
    std::cout << numbers[1] << std::endl;

    // doesn't work:
    // int nums[2] = {1, 2, 3};
    
    // hehe I love this language
    std::cout << numbers[3] << std::endl;

    // so I tried this because I thought it would be funny
    // it was

    // what I learned was that you can do this
    // but then the code will crash with "stack smashing detected"
    // I'm now convinced that the c++ compiler is shitty
    // what's really funny is that the code crashes *after* the `*ptr = 42`
    // so the computer tries to stop you from exploiting buffer overflow
    // but only after you exploit buffer overflow
    int* ptr = &numbers[3];
    *ptr = 42;
    std::cout << numbers[3] << std::endl;
}