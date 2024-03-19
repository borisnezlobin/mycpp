#include <bits/stdc++.h>
using namespace std;
#define INF 4611686018427387902
typedef long long ll;

// I'm not sure why this solution doesn't work (typical)
// it seems like it should work, but a lot of the table is
// still INF at the end of the code execution
int main(){
    int n = 0;
    cin >> n;

    vector<vector<ll>> table(n, vector<ll>(n, INF));

    for (int i = 0; i < n; i++) {
        table[i][i] = 0;
    }

    for(int i = 0; i < n - 1; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        table[from - 1][to - 1] = cost;
    }


    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (table[i][j] > table[i][k] + table[k][j]) {
                    table[i][j] = table[i][k] + table[k][j];
                }
            }
        }
    }

    ll count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            count += table[i][j];
        }
    }

    cout << count;

    return 0;
}