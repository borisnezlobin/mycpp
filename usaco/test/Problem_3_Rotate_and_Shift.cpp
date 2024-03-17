// solution (TLE on cases 8+) to USACO bronze P3 to test submission and CPH extension
// it all works so it looks like now I have to do the actual contest

#include <stdio.h>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, t;
    cin >> n >> k >> t;

    vector<int> actives(k);

    for(int i = 0; i < k; i++){
        cin >> actives[i];
    }

    vector<int> cows(n);

    for(int i = 0; i < n; i++){
        cows.at(i) = i;
    }

    for(int i = 0; i < t; i++){
        int last = cows.at(actives.at(actives.size() - 1));
        for(int j = 0; j < actives.size(); j++){
            int temp = cows.at(actives.at(j));
            cows.at(actives.at(j)) = last;
            last = temp;
            actives.at(j) = (actives.at(j) + 1) % n;
        }
    }

    for(int i = 0; i < cows.size(); i++){
        cout << cows.at(i);
        if(i != cows.size() - 1) cout << " ";
    }

    cout << "\n";

    return 0;
}