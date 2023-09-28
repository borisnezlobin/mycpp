#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Rectangle {
    ll start;
    ll length;
    ll height;
    ll end;

    Rectangle(ll start, ll length, ll height) : start { start }, length { length }, height { height }, end { start + length } {};

    string toString(){ return "[" + to_string(start) + ": (" + to_string(length) + ", " + to_string(height) + ")]"; }
};

struct CompareByStartIndex {
    bool operator()(const Rectangle* l, const Rectangle* r) {
        return l->start > r->start;
    }
};

struct CompareByHeight {
    bool operator()(const Rectangle* l, const Rectangle* r) {
        return l->height < r->height;
    }
};

struct IndexToRect {
    ll index;
    Rectangle* ptr;

    IndexToRect(): index { 0 }, ptr { nullptr } {};
    IndexToRect(ll index, Rectangle* ptr):
        index { index },
        ptr { ptr }
    {};

    string toString(){
        return string("(itr [") + to_string(index) + "])";
    }
};

bool compareIndexToRect(const IndexToRect& a, const IndexToRect& b){
    return a.index < b.index;
}

int main(int argc, char const *argv[]){
    bool isDev = false;
    ll area = 0;
    int n = 0;
    ll furthest = 0;

    cin >> n;

    // sorted by start index
    vector<Rectangle*> chunks;
    priority_queue<Rectangle*, vector<Rectangle*>, CompareByStartIndex> pq;
    IndexToRect points[n * 2];

    for (int i = 0; i < n; i++){
        ll start = -1;
        ll end = -1;
        ll height = -1;
        cin >> start >> end >> height;
        Rectangle* rect = new Rectangle(start, end - start, height);
        if(end > furthest) furthest = end;
        pq.push(rect);
        IndexToRect* itrone = new IndexToRect(start, rect);
        IndexToRect* itrtwo = new IndexToRect(end, rect);
        points[i * 2] = *itrone;
        points[i * 2 + 1] = *itrtwo;
    }

    int length = sizeof(points) / sizeof(points[0]);
    if(isDev) cout << "arr length " << length << "\n";
    sort(points, points + length, compareIndexToRect);

    if(isDev){
        for(int i = 0; i < length; i++){
            cout << points[i].toString() << " ";
        }
        cout << "\n";
    }

    if(isDev) cout << "furthest: " << furthest << "\n";

    priority_queue<Rectangle*, vector<Rectangle*>, CompareByHeight> heights;
    Rectangle* currentChunk = nullptr;

    for(int i = 0; i < length; i++){
        if(isDev) cout << "now considering " << points[i].index << "\n";
        Rectangle* rect = points[i].ptr;
        if(rect->start == points[i].index){
            if(isDev) cout << "new rectangle is starting: " << rect->toString() << "\n";
            if(currentChunk == nullptr || currentChunk->height < rect->height){
                if(isDev) cout << "this new rectangle is taller than current chunk\n";
                Rectangle* newChunk = new Rectangle(points[i].index, furthest - points[i].index, rect->height);
                if(currentChunk != nullptr){
                    currentChunk->length = points[i].index - currentChunk->start;
                    chunks.push_back(currentChunk);
                }
                currentChunk = newChunk;
                if(isDev) cout << "new chunk: " << currentChunk->toString() << "\n";
            }
            // do shit
            heights.push(rect);
        }

        if(!heights.empty()){
            Rectangle* tallest = heights.top();
            while(tallest != nullptr && tallest->end == points[i].index){
                if(isDev) cout << "current tallest rectangle is gone: " << tallest->toString() << "\n";
                heights.pop();
                // tallest rectangle has ended, we need to make a new chunk
                // pops infinitely
                while(!heights.empty() && heights.top()->end < points[i].index){
                    if(isDev) cout << "popping this rect, it's done " << heights.top()->toString() << "\n";
                    heights.pop();
                    if(isDev) cout << "size of heights: " << heights.size() << "\n";
                }

                // now, heights.top() is the tallest active rectangle
                // create a new chunk with this new rectangle
                // special case if heights is empty, there are no active rectangles
                if(heights.empty()){
                    if(currentChunk != nullptr){
                        currentChunk->length = points[i].index - currentChunk->start;
                        chunks.push_back(currentChunk);
                    }
                    currentChunk = nullptr;
                    tallest = nullptr;
                    continue;
                }
                Rectangle* newTallest = heights.top();
                Rectangle* newChunk = new Rectangle(points[i].index, furthest - points[i].index, newTallest->height);
                if(currentChunk != nullptr){
                    currentChunk->length = points[i].index - currentChunk->start;
                    chunks.push_back(currentChunk);
                }
                currentChunk = newChunk;
                tallest = newTallest;
            }
        }
    }

    if(currentChunk != nullptr && (chunks.empty() || chunks.at(chunks.size() - 1))){
        chunks.push_back(currentChunk);
    }

    if(isDev) cout << "calulating area\n";
    // calculate area by iterating over all chunks
    for(size_t i { 0 }; i != chunks.size(); i++){
        if(isDev) cout << chunks.at(i)->toString() << " ";
        area += chunks.at(i)->length * chunks.at(i)->height;
    }

    cout << area << "\n";

    return 0;
}