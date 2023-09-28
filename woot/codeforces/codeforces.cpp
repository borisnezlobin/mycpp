#include <bits/stdc++.h>
using namespace std;

char baseWord[11] { "codeforces" };

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        char word[11];
        cin >> word;

        int diffCount = 0;
        for(int j = 0; j < 10; j++){
            if(word[j] != baseWord[j]) diffCount++;
        }

        cout << diffCount << "\n";
    }

    return 0;
}