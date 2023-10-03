#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int people, edges = 0;
    cin >> people >> edges;
    vector<int> adjacency[edges];
    vector<int> transpose[edges];

    bool visited[edges] { false };
    bool oppVisited[edges] { false };

    stack<int> toVisit;

    for(int i = 0; i < edges; i++){
        int from, to;
        cin >> from >> to;
        adjacency[from - 1].push_back(to - 1);
        transpose[to - 1].push_back(from - 1);
    }

    const function<void(int)> DFS = [&](int node) -> void {
        visited[node] = true;
        for(int child: adjacency[node]){
            if(!visited[child]){
                DFS(child);
            }
        }
        toVisit.push(node);
    };

    const function<void(int)> DFS_REVERSE = [&](int node) -> void {
        oppVisited[node] = true;
        for(int child: transpose[node]){
            if(!oppVisited[child]){
                DFS_REVERSE(child);
            }
        }
    };

    for(int i = 0; i < edges; i++){
        DFS(i);
    }

    int scc = 0;
    while(!toVisit.empty()){
        int k = toVisit.top();
        toVisit.pop();
        if(!oppVisited[k]){
            scc++;
            DFS_REVERSE(k);
        }
    }

    cout << scc << "\n";

    return 0;
}