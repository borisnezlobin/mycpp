#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sig(int x){
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

int main(){
    bool dev = false;
    int num_grass = 0;
    cin >> num_grass;

    vector<ll> grasses (num_grass);
    ll sprays = 0;

    for(int i = 0; i < num_grass; i++){
        ll idk = 0;
        cin >> idk;
        grasses.at(i) = idk;
    };
    
    for(int i = 0; i < grasses.size(); i++){
        int target = 0;
        if(dev) cout << "at " << i << ", target is " << target << "\n";
        if(dev){
            cout << "current grass state of affairs:\n";
            for(int i = 0; i < grasses.size(); i++){
                cout << grasses.at(i) << " ";
            }
            cout << "\n";
        }
        if(grasses.at(i) != target){
            ll offset = grasses.at(i) - target;
            if(dev) cout << "the difference between current and target is " << offset << "\n";

            for(int j = i; j < grasses.size(); j++){
                ll added = offset * (j - i + 1);
                if(dev) cout << "subtracting " << added << " from index " << i << " (currently " << grasses.at(j) << ") to get " << grasses.at(j) - added << "\n";
                grasses.at(j) -= added;
            }

            sprays += sig(offset) * offset;
        }

        if(dev) cout << "done with index " << i << ". current spray count: " << sprays << "\n";
    }

    cout << sprays << "\n";

    return 0;
}