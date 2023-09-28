#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int a, b, c = 0;
        cin >> a >> b >> c;

        if((a + b >= 10) || (a + c >= 10) || (b + c >= 10))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}