/*
ID: boris.n1
TASK: gift1
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

struct Person {
    string name;
    int balance;

    Person(string name): name { name }, balance { 0 }{}
};

int main (int argc, char** argv){
    freopen("gift1.out", "w", stdout);

    map<string, int> namesToIndex;

    int numPeople = 0;
    cin >> numPeople;

    Person* accounts[numPeople];

    for(int i = 0; i < numPeople; i++){
        string name;
        cin >> name;
        namesToIndex.emplace(name, i);
        Person* newPerson = new Person(name);
        accounts[i] = newPerson;
    }

    for(int i = 0; i < numPeople; i++){
        string giver;
        cin >> giver;
        int amount, people;
        cin >> amount;
        cin >> people;
        if(amount == 0){
            for(int j = 0; j < people; j++){
                cin >> giver;
            }
            continue;
        }

        amount = amount - (amount % people);
        accounts[namesToIndex.at(giver)]->balance -= amount;
        amount = amount / people;
        
        for(int j = 0; j < people; j++){
            string person;
            cin >> person;
            accounts[namesToIndex.at(person)]->balance += amount;
        }
    }

    for(int i = 0; i < numPeople; i++){
        cout << accounts[i]->name << " " << accounts[i]->balance << "\n";
    }

    return 0;
}