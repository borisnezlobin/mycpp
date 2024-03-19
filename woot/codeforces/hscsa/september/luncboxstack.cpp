#include <bits/stdc++.h>
using namespace std;

int main(){
    int numPeople, stack;
    cin >> stack >> numPeople;

    priority_queue<int> pq;

    for(int i = 0; i < numPeople; i++){
        int person;
        cin >> person;

        pq.push(person);
    }

    int taken = 0;
    while(stack <= pq.top()){
        stack++;
        taken++;
        int temp = pq.top();
        pq.pop();
        pq.push(temp - 1);
    }

    cout << taken << "\n";

    return 0;
}