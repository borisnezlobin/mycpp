// #include <stdio.h>
// #include <iostream>
// #include <vector>
// #include <string.h>
// #include <queue>
// #include <algorithm>
// #include <regex>
// #include <utility>

// #define MAX_LONG 0x7fffffffffffffffL;
// typedef long long ll;
// using namespace std;

// int main(){
//     bool dev = true;
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
    
//     int numCows = 0;
//     cin >> numCows;

//     string cows;
//     cin >> cows;
//     cows = '0' + cows + '0';

//     if(dev) cout << "starting solution with input \"" << cows << "\"";

//     ll smallest_found = MAX_LONG;
//     queue<pair<string, int>*> to_visit;
//     to_visit.push(new pair<string, int> { cows, 0 });
//     vector<char>* state = new vector<char>(numCows + 2);

//     while(!to_visit.empty()){
//         pair<string, int>* top = to_visit.front();
//         to_visit.pop();
//         if(dev) cout << state->size() << ", " << top->first.length() << "\n";
//         for(int i = 0; i < top->first.length(); i++){
//             state->at(i) = top->first.at(i);
//         }

//         // count groups of 1s in it
//         int groups = state->at(0) == '1' ? 1 : 0;
//         for(int i = 1; i < state->size(); i++){
//             if(state->at(i) == '1' && state->at(i - 1) == '0') groups++;
//         }

//         if(dev) cout << top << " has " << groups << " groups\n";

//         // add every single possible combination to to_visit
//         // from 111 we can get: 110, 101, 011, 010

//         if(dev) cout << "string is now " << top << "\n";
//     }

//     cout << smallest_found << "\n";

//     return 0;
// }



#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
typedef long long ll;
using namespace std;

int main(){
    bool dev = false;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numCows = 0;
    cin >> numCows;

    string cows;
    cin >> cows;
    cows += '0';
    vector<int> state;

    if(dev) cout << "starting solution with input \"" << cows << "\"";

    char prev = ' ';
    int currentCount = 0;
    for(int i = 0; i < cows.length(); i++){
        if(cows.at(i) == '1'){
            currentCount++;
        }else if(currentCount > 0){
            state.push_back(currentCount);
            if(dev) cout << "added a block of " << currentCount << " infections\n"; 
            currentCount = 0;
        }
    }

    if(dev){
        cout << "infections:";
        for(size_t i { 0 }; i != state.size(); i++){
            cout << " " << state.at(i);
        }
    }

    while(true){
        bool possible = true;
        for(int i = 0; i < state.size(); i++){
            if(state.at(i) <= 2){
                possible = false;
                break;
            }
        }

        if(!possible) break;
        for(int i = 0; i < state.size(); i++){
            state.at(i) -= 2;
        }
    }

    if(dev) cout << "calculating sum\n";

    int sum = 0;
    for(int i = 0; i < state.size(); i++){
        sum += state.at(i);
    }

    cout << sum << "\n";

    return 0;
}
