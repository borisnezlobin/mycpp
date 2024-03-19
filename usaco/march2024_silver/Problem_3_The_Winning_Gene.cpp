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

    int n = 0;
    cin >> n;

    string str;
    cin >> str;

    unordered_map<int, int> results;

    for(int k = 1; k <= n; k++){
        for(int l = 1; l <= k; l++){
            unordered_set<int> indices;
            multiset<pair<string, int>> window;

            for(int a = 0; a < k - l; a++){
                window.emplace(pair<string, int>(str.substr(a, l), a));
                if(dev) cout << "created window " << str.substr(a, l) << ", " << a << "\n";
            }

            for(int i = 0; i < n - l - 1; i++){
                indices.emplace((*window.begin()).second);
                auto it = window.find(pair<string, int>(str.substr(i, l), i));
                if(it != window.end()){
                    if(dev) cout << "erased window " << (*it).first << ", " << (*it).second << "\n";
                    window.erase(it);
                }

                window.emplace(pair<string, int>(str.substr(i + 1, l), i + 1));
            }

            results[indices.size()] += 1;
        }
    }

    for(int i = 1; i < n; i++){
        cout << results[i] << "\n";
    }

    return 0;
}