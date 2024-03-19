#include <bits/stdc++.h>
using namespace std;

// lmao the idea is basically any number that has at least two in a row can win
// so go over all numbers, 0 - N, and see if there's an occurence of 2 in a row
int main(){
    bool dev = false;
    int num_testcases = 0;
    cin >> num_testcases;

    // so I can use fori later
    for(int testcase = 0; testcase < num_testcases; testcase++){
        int N = 0;
        cin >> N;

        vector<int> prefs(N);


        // vector<int> last_seen(N, -5);
        // vector<int> works;
        // vector<bool> included(N, false);
        for(int i = 0; i < N; i++){
            int pref = 0;
            cin >> pref;
            if(dev) cout << "working with " << pref << "\n";
            // if(included.at(pref - 1)) continue;
            if(dev) cout << "did not skip, means that pref is not yet working\n";
            // if(i - last_seen.at(pref - 1) < 3){
            //     if(dev) cout << "pref works, was recently found\n";
            //     works.push_back(pref);
            //     included.at(pref - 1) = true;
            // }else{
            //     last_seen.at(pref - 1) = i;
            // }

            prefs.at(i) = pref;
        }

        vector<int> works { };
        for(int i = 1; i < N + 1; i++){
            for(int j = 1; j < prefs.size(); j++){
                if(dev) cout << "testing " << i << " at index " << j << "\n";
                if(dev) cout << prefs.at(j) << ", " << prefs.at(j - 1) << "\n";
                if(
                    prefs.at(j) == i &&
                    (
                        prefs.at(j - 1) == prefs.at(j) ||
                        (
                            j >= 2 && prefs.at(j) == prefs.at(j - 2)
                        )
                    )
                ){
                    works.push_back(i);
                    if(dev) cout << "added " << i << "\n";
                    break;
                }else{
                    // if(dev) cout << "compared " << prefs.at(j) << " and " << prefs.at(j - 2) << "\n";
                }
            }
        }

        if(works.size() == 0){
            if(dev) cout << "\n====\n";
            cout << "-1";
            if(dev) cout << "\n====";
            cout << "\n";
            continue;
        }
        if(dev) cout << "====\n";
        for(int i = 0; i < works.size(); i++){
            cout << works.at(i);
            if(i != works.size() - 1) cout << " ";
        }
        if(dev) cout << "\n====";
        cout << "\n";
    }
}