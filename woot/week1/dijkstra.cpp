#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX_LONG 9223372036854775807

struct Road {
    int from;
    int to;
    ll length;
    ll size;
    
    Road(int from, int to, ll length, ll size):
        from { from },
        to { to },
        length { length },
        size { size }
    {};

    string toString(){
        string str = "road: ";
        str += to_string(from) + "->";
        str += to_string(to) + ", with length ";
        str += to_string(length) + ".";
        return str;
    }
};

struct Field {
    bool visited;
    int id;
    ll bestimate;
    ll maxCowSize;
    vector<Road*> from;
    vector<Road*> to;

    Field():
        id { -1 },
        from { },
        to { },
        visited { false },
        bestimate { MAX_LONG },
        maxCowSize { 0 }
    {};

    string toString(){
        string str = "field " +  to_string(id) + ": " + to_string(bestimate) + ". roads from:\n";
        for(size_t i { 0 }; i != from.size(); i++){
            str += "\t" + from.at(i)->toString() + "\n";
        }

        return str;
    }
};

struct CompareByCowSize {
    bool operator()(const Field* l, const Field* r) {
        if(l->maxCowSize == r->maxCowSize){
            return l->bestimate > r->bestimate;
        }
        return l->maxCowSize < r->maxCowSize;
    }
};

int main(int argc, char** argv){
    bool isDev = false;
    int fieldsNum, roadsNum = 0;
    cin >> fieldsNum >> roadsNum;
    vector<Road*> roads;
    Field fields[fieldsNum];

    for(int i = 0; i < roadsNum; i++){
        int from, to = 1;
        ll length, size = 1;
        cin >> from >> to >> length >> size;
        Road* newRoad = new Road(from, to, length, size);
        fields[from - 1].id = from;
        fields[from - 1].from.push_back(newRoad);
        fields[to - 1].id = to;
        fields[to - 1].to.push_back(newRoad);
        roads.push_back(newRoad);
    }

    if(isDev) cout << "all roads generated\n";

    fields[0].bestimate = 0;
    fields[0].maxCowSize = MAX_LONG;

    priority_queue<Field*, vector<Field*>, CompareByCowSize> frontier;
    frontier.push(&fields[0]);
    if(isDev) cout << "starting di jk stra\n";

    while(!frontier.empty()){
        Field* front = frontier.top();
        if(isDev) cout << front->toString() << "\n";
        for(size_t i { 0 }; i != front->from.size(); i++){
            Road* road = front->from.at(i);
            if(isDev) cout << "now considering road " << road->toString() << "\n";
            Field* next = &fields[road->to - 1];

            ll pathLength = front->bestimate + road->length;
            ll maxCowSize = (front->maxCowSize > road->size ? road->size : front->maxCowSize);
            if(isDev) cout << "maxcowsize is " << maxCowSize << "\n";
            if(maxCowSize >= next->maxCowSize){
                // set bestimate if bestimate is not set
                // or pathlength is shorter than bestimate + the cowsize is the same
                if(next->bestimate == MAX_LONG ||
                    (next->bestimate > pathLength && next->maxCowSize == maxCowSize)
                ){
                    next->bestimate = pathLength;
                }
                next->maxCowSize = maxCowSize;
                // next->bestimate = pathLength;
                frontier.push(next);
            }
            
            // get length (this.bestimate + road.bestimate)
            // maxcowsize = min(this.maxcowsize, road.size)
            // if maxcowsize > road.to.maxcowsize
            //      set road.to.maxcowsize = maxcowsize
            //      update bestimate of road.to
            //      add road.to to frontier
            // /shrug
        }

        frontier.pop();
    }

    if(isDev){
        cout << "fields:\n";
        for(int i = 0; i < fieldsNum; i++){
            cout << "  " << fields[i].toString();
        }
        cout << "\n";
    }

    cout << fields[fieldsNum - 1].maxCowSize << " " << fields[fieldsNum - 1].bestimate << "\n";
}