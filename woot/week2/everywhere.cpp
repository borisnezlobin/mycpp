#include <bits/stdc++.h>
using namespace std;
#define INF numeric_limits<int>::max()
typedef long long ll;

int main(){
    bool dev = false;

    int n, m = 0;
    cin >> n >> m;

    ll table[n][n] { 0 };

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) table[i][j] == 0;
            else table[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++){
        int from, to = 0;
        ll weight = 0;
        cin >> from >> to >> weight;
        table[from - 1][to - 1] = weight;
    }

    // apply floyd-warshall (triple for-loop)
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(table[i][j] > table[i][k] + table[k][j])
                    table[i][j] = table[i][k] + table[k][j];
            }
        }
    }

    if(dev){
        cout << "table:\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(table[i][j] == INF) cout << "undef";
                else{ cout << table[i][j]; }
                if(j != n - 1) cout << ",\t\t";
            }
            cout << "\n";
        }
    }


    ll length = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            length += table[i][j];
        }
    }

    cout << length << "\n";

    return 0;
}