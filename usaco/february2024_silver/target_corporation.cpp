#include <stdio.h>
#include <iostream>
#include <utility>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

#define MAX_VALUE 9223372036854775807
#define MIN_VALUE -9223372036854775806

struct TargetVertex {
    ll x;
    ll y;
    int dir; // -1 if slope has to be negative (top right corner), 1 if slope has to be positive (bottom right corner), and 0 otherwise

    TargetVertex(ll x, ll y, int dir): x { x }, y { y }, dir { dir } {}
};

struct TargetCompare {
    bool operator()(const TargetVertex* l, const TargetVertex* r) const {
        if(l->x == r->x){
            return l->y > r->y;
        }
        return l->x < r->x;
    }
};

struct TargetCompareVertFlipped {
    bool operator()(const TargetVertex* l, const TargetVertex* r) const {
        if(l->x == r->x){
            return l->y < r->y;
        }
        return l->x < r->x;
    }
};

struct MinCompare {
    bool operator()(const ll l, const ll r) const {
        return l > r;
    }
};

int main() {
    bool dev = false;
    int testcases = 0;
    cin >> testcases;

    for (int i = 0; i < testcases; i++){
        int targets, leftmost = 0;
        cin >> targets;
        cin >> leftmost;

        priority_queue<ll> negative_slopes;
        priority_queue<ll, vector<ll>, MinCompare> positive_slopes;
        int num_zero_slopes = 0;
        priority_queue<TargetVertex*, vector<TargetVertex*>, TargetCompare> points;
        priority_queue<TargetVertex*, vector<TargetVertex*>, TargetCompare> pos_spec_points;
        priority_queue<TargetVertex*, vector<TargetVertex*>, TargetCompareVertFlipped> neg_spec_points;



        for(int i = 0; i < targets; i++){
            ll y1, y2, x2 = 0;
            cin >> y1;
            cin >> y2;
            cin >> x2;

            points.push(new TargetVertex(leftmost, y1, 0));
            points.push(new TargetVertex(leftmost, y2, 0));
            pos_spec_points.push(new TargetVertex(x2, y1, 1));
            neg_spec_points.push(new TargetVertex(x2, y2, -1));
        }

        for(int i = 0; i < targets * 4; i++){
            ll slope = 0;
            cin >> slope;
            if(slope > 0) {
                positive_slopes.push(slope);    
            }
            else if (slope < 0) {
                negative_slopes.push(slope);
            }else{
                num_zero_slopes++;
            }
        }

        // early return if impossible to reach all right-side target vertices
        if(positive_slopes.size() < targets || negative_slopes.size() < targets){
            cout << "-1\n";
            continue;
        }

        ll min = MAX_VALUE;
        ll max = MIN_VALUE;

        while(!pos_spec_points.empty()){
            TargetVertex* v = pos_spec_points.top();
            pos_spec_points.pop();

            ll intersect = 0;
            ll slope;
            if(v->dir > 0){
                slope = positive_slopes.top();
                positive_slopes.pop();
                intersect = v->y - slope * v->x;
            }else if (v->dir < 0){
                slope = negative_slopes.top();
                negative_slopes.pop();
                intersect = v->y - slope * v->x;
            }

            if(dev){
                cout << "for point " << v->dir << " * (" << v->x << ", " << v->y << "), found intersection at y=" << intersect << " (slope " << slope << ")\n";
            }

            if(intersect < min){
                min = intersect;
            }

            if(intersect > max){
                max = intersect;
            }
        }

        while(!neg_spec_points.empty()){
            TargetVertex* v = neg_spec_points.top();
            neg_spec_points.pop();

            ll intersect = 0;
            ll slope;
            if(v->dir > 0){
                slope = positive_slopes.top();
                positive_slopes.pop();
                intersect = v->y - slope * v->x;
            }else if (v->dir < 0){
                slope = negative_slopes.top();
                negative_slopes.pop();
                intersect = v->y - slope * v->x;
            }

            if(dev){
                cout << "for point " << v->dir << " * (" << v->x << ", " << v->y << "), found intersection at y=" << intersect << " (slope " << slope << ")\n";
            }

            if(intersect < min){
                min = intersect;
            }

            if(intersect > max){
                max = intersect;
            }
        }

        // consolidate all remaining points into one priority_queue
        priority_queue<ll, vector<ll>, MinCompare> slopes;

        while(!negative_slopes.empty()){
            slopes.push(negative_slopes.top());
            negative_slopes.pop();
        }

        while(!positive_slopes.empty()){
            slopes.push(positive_slopes.top());
            positive_slopes.pop();
        }
        
        for(int i = 0; i < num_zero_slopes; i++){
            slopes.push(0);
        }

        // figure out the rest
        while(!points.empty()){
            TargetVertex* v = points.top();
            points.pop();
            ll slope = slopes.top();
            slopes.pop();

            ll intersect = v->y - slope * v->x;

            if(dev){
                cout << "for point " << v->dir << " * (" << v->x << ", " << v->y << "), found intersection at y=" << intersect << ", (slope " << slope << " )\n";
            }

            if(intersect < min){
                min = intersect;
            }

            if(intersect > max){
                max = intersect;
            }
        }

        cout << max - min << "\n";
    }
}