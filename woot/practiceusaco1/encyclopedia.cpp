#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// I don't know why this solution doesn't work. It seems like a good idea and it
// works on all of the test cases I could come up with.
int main(){
    ll history, requests = 0;
    cin >> history >> requests;

    unordered_map<string, ll> book;
    ll time = 0;

    for(int i = 0; i < requests; i++){
        string query = "";
        cin >> query;
        if(book.find(query) != book.end()){
            ll lastIndex = book[query];

            if(lastIndex < i - history) time += 10;
            else time += 1;

            book[query] = i;
        }else{
            book.emplace(query, i);
            time += 10;
        }
    }

    cout << time << "\n";

    return 0;
}