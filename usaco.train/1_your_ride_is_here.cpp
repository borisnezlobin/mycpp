/*
ID: boris.n2
LANG: C++
TASK: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout("ride.out");
    ifstream fin("ride.in");

    string comet, group;
    fin >> comet >> group;

    int comet_product = 1;
    int group_product = 1;
    for (int i = 0; comet[i] != '\0'; i++) {
        comet_product *= comet[i] - 'A' + 1;
    }
    for (int i = 0; group[i] != '\0'; i++) {
        group_product *= group[i] - 'A' + 1;
    }
    
    if (comet_product % 47 == group_product % 47) {
        fout << "GO" << endl;
    } else {
        fout << "STAY" << endl;
    }

    return 0;
}