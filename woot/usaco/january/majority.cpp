// perfect
#include <bits/stdc++.h>
using namespace std;

// lmao the idea is basically any number that has at least two in a row can win
// so go over all numbers, 0 - N, and see if there's an occurence of 2 in a row
int main()
{
    bool dev = false;
    int num_testcases = 0;
    cin >> num_testcases;

    // so I can use fori later
    for (int testcase = 0; testcase < num_testcases; testcase++)
    {
        int N = 0;
        cin >> N;

        vector<int> prefs(N);

        // FAILS:
        /*
        1
        5
        1 5 5 1 2

        prints: 1 2 5
        */

        vector<int> last_seen(N, -500);
        vector<int> works;
        vector<bool> included(N, false);
        for (int i = 0; i < N; i++)
        {
            int pref = 0;
            cin >> pref;
            if(dev) cout << "working with " << pref << "\n";
            if (included.at(pref - 1))
                continue;
            if(dev) cout << "did not skip, means that pref is not yet working\n";
            if (last_seen.at(pref - 1) > i - 3 && last_seen.at(pref - 1) >= 0)
            {
                if(dev) cout << "pref works, was recently found\n";
                if(dev && pref == 2) cout << "seen at " << last_seen.at(pref - 1) << "\n";
                works.push_back(pref);
                included.at(pref - 1) = true;
            }

            last_seen.at(pref - 1) = i;
        }

        std::sort(works.begin(), works.end());

        if (works.size() == 0)
        {
            cout << "-1\n";
            continue;
        }

        for (int i = 0; i < works.size(); i++)
        {
            cout << works.at(i);
            if (i != works.size() - 1)
                cout << " ";
        }
        cout << "\n";
    }
}