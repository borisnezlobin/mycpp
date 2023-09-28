#include <bits/stdc++.h>
using namespace std;
#define ll long long
using arrtype = std::array<char, 18>;

struct ArrayHasher {
    std::size_t operator()(const arrtype& arr) const {
        std::hash<char> hasher;
        std::size_t result = 0;
        for (const auto& element : arr) {
            result ^= hasher(element) + 0x9e3779b9 + (result << 6) + (result >> 2);
        }
        return result;
    }
};

bool isSolution(arrtype* perm){
    // check if permutation is valid
    short leftPtr = 0;
    short rightPtr = 17;

    while(perm->at(rightPtr) == 3) rightPtr--;

    while(perm->at(leftPtr) == 0) leftPtr++;
    short leftest = perm->at(leftPtr);

    while(leftPtr < rightPtr){
        while(perm->at(leftPtr) == 0) leftPtr++;
        while(perm->at(rightPtr) == 0) rightPtr--;

        if(leftPtr >= rightPtr) break;

        // left == first item on left && right != first item on left
        if(!(perm->at(leftPtr) == leftest && perm->at(rightPtr) != perm->at(leftPtr))){
            return false;
        }

        leftPtr++;
        rightPtr--;
    }

    return true;
}

arrtype* swap(arrtype* a, char at){
    arrtype* newArray = new arrtype;
    char space_at = -1;

    for(char i = 0; i < 18; i++){
        newArray->at(i) = a->at(i);
        if(newArray->at(i) == 0) space_at = i - 1;
    }

    pair<char, char> temp(newArray->at(at), newArray->at(at + 1));
    newArray->at(at) = 0;
    newArray->at(at + 1) = 0;
    newArray->at(space_at) = temp.first;
    newArray->at(space_at + 1) = temp.second;

    return newArray;
}

int main(int argc, char** argv){
    bool dev = false;

    int subcases = -1;
    cin >> subcases;

    for(int i = 0; i < subcases; i++){
        short length;
        cin >> length;
        char s[length];
        cin >> s;

        arrtype real;

        for(short i = 0; i < 18; i++){
            if(i >= length){
                real[i] = 3;
                continue;
            }

            if(s[i] == 'G') real[i] = 1;
            else if(s[i] == 'H') real[i] = 2;
            else real[i] = 0;
        }

        unordered_set<arrtype, ArrayHasher> visited;
        queue<pair<arrtype*, char>*> tbv;
        tbv.push(new pair<arrtype*, char> { &real, 0 });
        // store all "visited" arrays
        //      hashset
        bool flag = false;
        while(!tbv.empty()){
            if(dev) cout << "checking another permutation\n";
            pair<arrtype*, char>* top = tbv.front();
            if(dev) cout << "current array is solution: " << isSolution(top->first) << "\n";
            if(isSolution(top->first)){
                cout << static_cast<int>(top->second) << "\n";
                if(dev) cout << "found a solution\n";
                flag = true;
                break;
                // replace tbv with empty queue
            }
            // calculate all permutations
            for(short i = 0; i < 17; i++){
                if(top->first->at(i) == 3 || top->first->at(i + 1) == 3) break;
                if(top->first->at(i) == 0 || top->first->at(i + 1) == 0) continue;

                arrtype* a = swap(top->first, i);
                if(visited.find(*a) == visited.end()){
                    visited.emplace(*a);
                    tbv.push(new pair<arrtype*, char> { a, top->second + 1 });
                }
            }
            // if not visited, visit
            // addd to queue
            tbv.pop();
        }

        if(!flag) cout << "IMPOSSIBLE\n";
        // add current array to "tbv"
        //      queue of arrays
        // for current tbv top:
        //      meets criteria?
        //          iterate over array, first 
        //          return depth
        //      else: calculate all possible (unvisited) moves
        //      add current array to visited
    }

    return 0;
}