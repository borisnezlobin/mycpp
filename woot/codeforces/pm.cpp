#include <bits/stdc++.h>
using namespace std;

// shit's too easy
int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;

        if(a + b == c) cout << "+\n";
        else cout << "-\n";
    }
}