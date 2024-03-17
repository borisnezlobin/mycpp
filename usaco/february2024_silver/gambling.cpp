#include <stdio.h>
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

#define MAX_VALUE 9223372036854775807
#define MIN_VALUE -9223372036854775806

struct GameStep {
    int marbles;
    int steps;
    string path;

    GameStep(int marbles, int steps, string path) : marbles(marbles), steps(steps), path(path) {}
};

struct Turn {
    vector<int> marbles;

    Turn(vector<int> marbles) : marbles(marbles) {}
};

struct GameStepCompare {
    bool operator()(const GameStep &a, const GameStep &b) {
        return a.path.compare(b.path) > 0;
    }
};

int max(int a, int b){
    return a > b ? a : b;
}

int worst_case(Turn turn, GameStep step, char guess){
    // guess is "even" or "odd"

    if(guess == 'E'){
        ll best_even = MIN_VALUE;
        ll worst_odd = MIN_VALUE;

        for(int i = 0; i < turn.marbles.size(); i++){
            if(turn.marbles[i] % 2 == 0){
                best_even = max(best_even, turn.marbles[i]);
            } else {
                worst_odd = max(worst_odd, turn.marbles[i]);
            }
        }

        if(worst_odd == MIN_VALUE){
            return best_even;
        } else {
            return -worst_odd;
        }
    } else {
        ll best_odd = MIN_VALUE;
        ll worst_even = MIN_VALUE;

        for(int i = 0; i < turn.marbles.size(); i++){
            if(turn.marbles[i] % 2 == 1){
                best_odd = max(best_odd, turn.marbles[i]);
            } else {
                worst_even = max(worst_even, turn.marbles[i]);
            }
        }

        if(worst_even == MIN_VALUE){
            return best_odd;
        } else {
            return -worst_even;
        }
    
    }
}

void print_path(string path){
    for(int i = 0; i < path.size(); i++){
        if(path.at(i) == 'E'){
            cout << "Even";
        } else {
            cout << "Odd";
        }

        if(i != path.size() - 1){
            cout << " ";
        }
    }
}

int main() {
    bool dev = false;
    int testcases = 0;
    cin >> testcases;

    for (int i = 0; i < testcases; i++){
        int marbles, turns, choices = 0;
        cin >> marbles;
        cin >> turns;
        cin >> choices;

        vector<Turn> game;
        for (int j = 0; j < turns; j++){
            vector<int> marbles;
            for (int k = 0; k < choices; k++){
                int marble;
                cin >> marble;
                marbles.push_back(marble);
            }
            game.push_back(Turn(marbles));
        }

        priority_queue<GameStep, vector<GameStep>, GameStepCompare> pq_current;
        priority_queue<GameStep, vector<GameStep>, GameStepCompare> pq_next;
        pq_current.push(GameStep(marbles, 0, ""));

        GameStep win = GameStep(-1, 0, "");

        for(int i = 0; i < turns + 1; i++){
            while(!pq_current.empty()){
                GameStep current = pq_current.top();
                if(dev){
                    cout << "current: " << current.marbles << " " << current.steps << " " << current.path << endl;
                }
                if(current.steps == turns){
                    win = current;
                    if(dev){
                        cout << "win: " << win.marbles << " " << win.steps << " " << win.path << endl;
                    }
                    break;
                }
                pq_current.pop();

                GameStep even = GameStep(current.marbles + worst_case(game.at(i), current, 'E'), current.steps + 1, current.path + 'E');
                if(even.marbles > 0){
                    pq_next.push(even);
                }
                GameStep odd = GameStep(current.marbles + worst_case(game.at(i), current, 'O'), current.steps + 1, current.path + 'O');
                if(odd.marbles > 0){
                    pq_next.push(odd);
                }
            }

            if(pq_next.empty()){
                if(dev){
                    cout << "END GAME!! " << win.marbles << " " << win.steps << " " << win.path << endl;
                }
                if(win.path.size() == 0){
                    cout << "-1" << endl;
                } else {
                    print_path(win.path);
                    cout << endl;
                }
                break;
            }

            pq_current = pq_next;
            while(!pq_next.empty()){
                pq_next.pop();
            }
        }
    }
}