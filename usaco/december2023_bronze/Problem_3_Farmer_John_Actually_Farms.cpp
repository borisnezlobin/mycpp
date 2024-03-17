#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
typedef long long ll;
using namespace std;

struct plant {
    ll height;
    ll growth;
    int rank;

    plant(ll height, ll growth, int rank): height { height }, growth { growth }, rank { rank } {}
};

bool compare_plants_by_rank(plant* i, plant* j) { return i->rank < j->rank; }

int main(){
    bool dev = false;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;

    for(int z = 0; z < T; z++){
        int num_plants = 0;
        cin >> num_plants;

        vector<ll> heights(num_plants);
        for(int i = 0; i < num_plants; i++){
            cin >> heights.at(i);
        }

        vector<ll> growths(num_plants);
        for(int i = 0; i < num_plants; i++){
            cin >> growths.at(i);
        }

        vector<ll> winners(num_plants);
        for(int i = 0; i < num_plants; i++){
            cin >> winners.at(i);
        }

        vector<plant*> plants(num_plants);
        for(int i = 0; i < num_plants; i++){
            plants.at(i) = new plant(heights.at(i), growths.at(i), winners.at(i));
        }

        if(dev) cout << "starting solution\n";

        if(num_plants == 1){
            cout << "0\n";
            continue;
        }

        sort(plants.begin(), plants.end(), compare_plants_by_rank);

        vector<ll> days_to_overtake(num_plants - 1);
        for(int i = 0; i < num_plants - 1; i++){
            ll height_diff = plants.at(i + 1)->height - plants.at(i)->height;
            ll growth_diff = plants.at(i)->growth - plants.at(i + 1)->growth;
            if(
                (plants.at(i)->height > plants.at(i + 1)->height && plants.at(i)->growth >= plants.at(i + 1)->growth) ||
                (plants.at(i)->height >= plants.at(i + 1)->height && plants.at(i)->growth > plants.at(i + 1)->growth)
            ){
                days_to_overtake.at(i) = 0;
                continue;
            }
            if(growth_diff <= 0 && height_diff >= 0){
                days_to_overtake.at(i) = -1;
                continue;
            }

            days_to_overtake.at(i) = (int) ((1.0 * height_diff) / growth_diff + 0.5);
            if(height_diff % growth_diff == 0) days_to_overtake.at(i) += 1;
        }

        if(dev){
            cout << "days to overtake: ";
            for(int i = 0; i < num_plants - 1; i++){
                cout << " " << days_to_overtake.at(i);
            }
            cout << "\n";
        }

        ll max = -3;
        for(int i = 0; i < num_plants - 1; i++){
            if(max < days_to_overtake.at(i)){
                max = days_to_overtake.at(i);
            }

            if(days_to_overtake.at(i) == -1){
                cout << "-1\n";
                max = -2;
                break;
            }
        }

        if(max != -2) cout << max << "\n";
    }

    return 0;
}