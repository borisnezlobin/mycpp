#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    if(k < 75){
        cout << "0\n";
        return 0;
    }
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int l, r = 0;
        cin >> l >> r;
        if(r - l < 74) continue;
        v.push_back({l, r});
    }
    sort(v.begin(), v.end());
    int maxi = 0;
    int current = 0; // students available
    int left = 0;
    int right = 0;
    while (right < v.size()) {
        if (right < v.size() - 1) {
            if (v[right + 1].first + 74 - (v[left].second - 74) + 1 <= k) {
                right++;
            } else {
                left++;
            }
        } else {
            break;
        }
        maxi = max(maxi, right - left + 1);
    }
    cout << maxi << endl;
    return 0;
}