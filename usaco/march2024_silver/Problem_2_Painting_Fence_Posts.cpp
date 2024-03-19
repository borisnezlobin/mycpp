#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> point;
typedef pair<point, int> ipoint;

int main(){
    bool dev = true;

    int n, p = 0;
    cin >> n >> p;

    unordered_map<ll, vector<ipoint>> xlookup;
    unordered_map<ll, vector<ipoint>> ylookup;

    for(int i = 0; i < p; i++){
        int x, y = 0;
        cin >> x >> y;
        ipoint p (point(x, y), i);
        xlookup[x].push_back(p);
        ylookup[y].push_back(p);
    }

    vector<ipoint> posts(p);
    ipoint next = (*xlookup.begin()).second.at(0);
    bool x = true;
    for(int i = 0; i < p; i++){
        posts[i] = next;
        if(x){
            // if(xlookup.at(next.first.first).)
        }
    }

    return true;
}