/*
ID: mike51
TASK: beads
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int main() {
    ofstream fout("beads.out");
    ifstream fin("beads.in");
    int n;
    string s;
    fin >> n >> s;
    vector<int> lr(n), lb(n), rr(n), rb(n);
    for (int i = 1; i <= 2*n; ++i) {
        if (s[i%n] == 'b') {
            lr[i%n] = 0;
        } else {
            lr[i%n] = lr[(i-1)%n] + 1;
        }
        if (s[i%n] == 'r') {
            lb[i%n] = 0;
        } else {
            lb[i%n] = lb[(i-1)%n] + 1;
        }
    }
    for (int i = 2*n; i; --i) {
        if (s[i%n] == 'b') {
            rr[i%n] = 0;
        } else {
            rr[i%n] = rr[(i+1)%n] + 1;
        }
        if (s[i%n] == 'r') {
            rb[i%n] = 0;
        } else {
            rb[i%n] = rb[(i+1)%n] + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, lr[i%n]+rb[(i+1)%n]);
        ans = max(ans, lb[i%n]+rr[(i+1)%n]);
    }
    fout << min(ans, n) << '\n';
    return 0;
}
