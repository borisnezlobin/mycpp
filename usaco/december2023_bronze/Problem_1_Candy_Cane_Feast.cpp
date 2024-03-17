// problem 1, perfect score

#include <stdio.h>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

struct height {
    ll start;
    ll end;

    height(ll start, ll end): start { start }, end { end } {}
};

int main(){
    bool dev = false;
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int numCows, numCanes = 0;
    cin >> numCows >> numCanes;

    vector<ll> cows(numCows);
    vector<height*> canes(numCanes);

    for(int i = 0; i < numCows; i++){
        ll cowHeight = 0;
        cin >> cowHeight;

        cows.at(i) = cowHeight;
    }

    for(int i = 0; i < numCanes; i++){
        ll caneHeight = 0;
        cin >> caneHeight;

        canes.at(i) = new height(0, caneHeight);
        if(dev) cout << "added cane " << canes.at(i)->end << "\n";
    }

    for(int i = 0; i < numCanes; i++){
        if(dev) cout << "\n\ncane is now " << canes.at(i)->end << "\n\n";
        for(int j = 0; j < numCows; j++){
            if(canes.at(i)->start > canes.at(i)->end) break;
            if(dev) cout << "now considering cow with height " << cows.at(j) << "\n";

            ll difference = cows.at(j) - canes.at(i)->start;
            if(difference < 0) continue;

            if(cows.at(j) >= canes.at(i)->end){
                cows.at(j) += canes.at(i)->end - canes.at(i)->start;
                break;
            }
            cows.at(j) += difference;
            canes.at(i)->start += difference;
        }
    }

    for(int i = 0; i < numCows; i++){
        cout << cows.at(i) << "\n";
    }

    return 0;
}