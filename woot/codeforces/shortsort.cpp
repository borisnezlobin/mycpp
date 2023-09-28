#include <bits/stdc++.h>
using namespace std;

// works on my machine with my silly little c++17, codeforces bad

char valid[][4] {
    "abc",
    "acb",
    "bac",
    "cba"
};

bool compare(char one[3], char two[3]){
    for(int i = 0; i < 3; i++){
        if(one[i] != two[i]) return false;
    }

    return true;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        char input[3];
        cin >> input;
        for(int j = 0; j < 4; j++){
            if(compare(input, valid[j])){
                cout << "YES\n";
                break;
            }

            if(j == 3) cout << "NO\n";
        }
    }
}