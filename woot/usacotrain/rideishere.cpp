/*
ID: boris.n1
TASK: ride
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    freopen("ride.out", "w", stdout);
    string comet, group;
    getline(cin, comet);
    getline(cin, group);

    long long cometMod = 1;
    for(int i = 0; i < comet.size(); i++){
        int cope = comet.at(i) - 64;
        if(cope < 1) continue;
        cometMod *= cope;
    }
    cometMod = cometMod % 47;

    long long groupMod = 1;
    for(int i = 0; i < group.size(); i++){
        int cope = group.at(i) - 64;
        if(cope < 1) continue;
        groupMod *= cope;
    }

    groupMod = groupMod % 47;

    cout << (groupMod == cometMod ? "GO" : "STAY");
    cout << "\n";
}