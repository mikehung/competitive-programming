/*
ID: mike51
TASK: gift1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int NP, NG, amount;
string name;
map<string, int> id;
vector<int> money(15);
vector<string> names(15);

int main() {
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");
    fin >> NP;
    for (int i = 0; i < NP; ++i) {
        fin >> name;
        id[name] = i;
        names[i] = name;
    }
    while (fin >> name >> amount >> NG) {
        if (!NG) continue;
        money[id[name]] += -amount + (amount % NG);
        for (int i = 0; i < NG; ++i) {
            fin >> name;
            money[id[name]] += (amount / NG);
        }
    }
    for (int i = 0; i < NP; ++i) {
        fout << names[i] << ' ' << money[id[names[i]]] << '\n';
    }
    return 0;
}
