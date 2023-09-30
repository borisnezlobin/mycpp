#include <bits/stdc++.h>
using namespace std;
typdef long long ll;

int[] base = {
    {0, 5, 4},
    {7, 3, -1},
    {2, 1, 6}
}

int main(){
    ll k = 0;
    cin >> k;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << k + base[i][j];
            if(j != 2) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}