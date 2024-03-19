#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    bool dev = true;
    ll n, numFarmers = 0;
    cin >> n >> numFarmers;
    ll interviews[n];

    // O(n)
    for (int i = 0; i < n; i++){
        ll len = 0;
        cin >> len;
        interviews[i] = len;
    }

    ll time = 0;
    multiset<pair<ll, ll>> farmers;
    unordered_map<ll, unordered_set<ll>> equiv;

    // O(n)
    for(int i = 0; i < numFarmers; i++){
        pair<ll, ll> p (interviews[i], i);
        farmers.emplace(p);
        equiv[i].emplace(i);
    }

    ll lastTime = -1;
    for(int i = numFarmers; i < n; i++){
        pair<ll, ll> farmer = (*farmers.begin());
        time = farmer.first;

        if(lastTime != time && farmer.first == (*++farmers.begin()).first){
            for(auto j = farmers.begin(); (*j).first == farmer.first; j++){
                equiv[farmer.second].emplace((*j).second);
                equiv[(*j).second].emplace(farmer.second);
            }
            lastTime = time;
        }

        farmers.erase(farmers.begin());
        farmer.first = time + interviews[i];
        farmers.insert(farmer);
    }

    std::cout << (*farmers.begin()).first << "\n";
    
    ll winner = (*farmers.begin()).second;

    // O(something big)
    vector<bool> visited(numFarmers, false);
    visited.at(winner) = true;
    unordered_set<ll> equivs;
    unordered_set<ll> visit { winner };
    while(!visit.empty()){
        unordered_set<ll> new_visit;
        for(auto i = visit.begin(); i != visit.end(); i++){
            equivs.emplace(*i);
            for(auto j = equiv[*i].begin(); j != equiv[*i].end(); j++){
                if(!visited[*j]){
                    new_visit.emplace(*j);
                    visited.at(*j) = true;
                }
            }
        }

        visit = new_visit;
    }

    // O(n)
    for(int i = 0; i < numFarmers; i++){
        // if(equiv[winner].find(i) != equiv[winner].end()){
        if(equivs.find(i) != equivs.end()){
            std::cout << "1";
        } else {
            std::cout << "0";
        }
    }

    std::cout << "\n";

    return 0;
}