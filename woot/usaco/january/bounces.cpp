// like 16 of 20 cases (tle on others)

#include <bits/stdc++.h>
using namespace std;

int main(){
    bool dev = false;
    int N, S = 0;
    cin >> N >> S;

    vector<int> types(N);
    vector<int> strengths(N);
    vector<bool> broken(N);

    for(int i = 0; i < N; i++){
        int type, strength = 0;

        cin >> type >> strength;

        types.at(i) = type;
        strengths.at(i) = strength;
        broken.at(i) = false;
    }

    int pos = S;
    int strength = 1;
    int numBroken = 0;
    int dir = 1;

    while(pos > 0 && pos < types.size() + 1){
        if(types.at(pos - 1) == 0){
            // is a launch pad
            if(dev) cout << "landed on jump pad at position " << pos;
            strength += strengths.at(pos - 1);
            dir *= -1;
            if(dev) cout << ". new strength: " << strength << "\n";
        }else{
            // check if breaks
            if (dev) cout << "landed on a target at position " << pos;
            if(!broken.at(pos - 1) && strengths.at(pos - 1) <= strength){
                numBroken++;
                broken.at(pos - 1) = true;
                if(dev) cout << ". it breaks!";
            }
            if(dev) cout << "\n";
        }

        pos += strength * dir;
    }

    cout << numBroken << "\n";

    return 0;
}