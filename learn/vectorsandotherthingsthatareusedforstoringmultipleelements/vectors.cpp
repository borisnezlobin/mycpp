#include <vector>
#include <string>
#include <iostream>
using namespace std;

string print_vector(vector<string> vec){
    string ret = "[";
    for(int i = 0; i < vec.size(); i++){
        // so turns out c++ is funny and while you can use [] to get an element,
        // there's no bounds checking which just seems like the most hilarious and
        // easy-to-exploit security vulnerability ever
        ret += vec.at(i);
        if(i != vec.size() - 1) ret += ", ";
    }
    return ret + "]";
}

int main(int argc, char** argv){
    vector<string> strs1 = { "so", "this", "is", "one", "way" };
    vector<string> strs2 { "and", "this", "is", "another", "way" };
    vector<string> strs3(3, "yet another");
    strs1.push_back("\"nooooo, we can't have a decently named 'add array to function' method, it must be 'push_back'\"");
    cout << "strs1: " + print_vector(strs1);
    cout << "\nstrs2: " + print_vector(strs2);
    cout << "\nstrs3: " + print_vector(strs3) << endl;

    return 0;
}