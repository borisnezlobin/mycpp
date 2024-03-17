#include <stdio.h>
#include <iostream>
#include <utility>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

#define MAX_VALUE 9223372036854775807;
#define MIN_VALUE -9223372036854775806;

int dist_from(string tube, char c){
    int count = 0;
    char prev = c;
    for (int i = 0; i < tube.size(); i++){
        if (tube.at(i) != prev){
            prev = tube.at(i);
            count++;
        }
    }

    return count;
}

int main() {
    bool dev = false;
    int testcases = 0;
    cin >> testcases;

    for (int i = 0; i < testcases; i++){
        int depth, p = 0;
        cin >> depth;
        cin >> p;

        // if p = 1, just print the solution
        // if p = 2, print the way to get to a solution-like thing
        // if p = 3, must be the exact solution AND steps

        string s1, s2;
        cin >> s1 >> s2;

        int s1_1 = dist_from(s1, '1');
        int s1_2 = dist_from(s1, '2');
        int s2_1 = dist_from(s2, '1');
        int s2_2 = dist_from(s2, '2');

        if(dev){
            cout << "s1_1: " << s1_1 << endl;
            cout << "s1_2: " << s1_2 << endl;
            cout << "s2_1: " << s2_1 << endl;
            cout << "s2_2: " << s2_2 << endl;
        }

        int steps = 0;

        // this genius solution *should* work for test cases 2-6... but instead the grader says:
        /*
        Incorrect answer on sample input case -- details below

            The grader for this problem says:
                W
                basic_ios::clear: iostream error

            Your output (written to stdout):
                4
        */
        // so idk man
        if(p == 1){
            int steps1 = s1_1 + s2_2;
            int steps2 = s1_2 + s2_1;

            if(steps1 < steps2){
                cout << steps1 + 1 << endl;
            } else {
                cout << steps2 + 1 << endl;
            }
        }else{

        }
    }
}