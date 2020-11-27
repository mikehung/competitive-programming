#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> rule(8, vector<int>(5));
    for (int i = 0; i < 8; ++i) {
        int v0 = i&1;
        int v1 = (i>>1)&1;
        int v2 = (i>>2)&1;
        rule[i][0] = v0 ^ v1;
        rule[i][1] = v1 ^ v2;
        rule[i][2] = v0 & v1;
        rule[i][3] = v0 & v2;
        rule[i][4] = v1 & v2;
    }
    int n;
    cin >> n;
    vector<int> xors(n-1);
    for (int i = 0; i < n-1; ++i) {
        cout << "XOR " << i+1 << ' ' << i+2 << endl;
        cin >> xors[i];
    }
    vector<int> ands(3);
    cout << "AND 1 2" << endl;
    cin >> ands[0];
    cout << "AND 1 3" << endl;
    cin >> ands[1];
    cout << "AND 2 3" << endl;
    cin >> ands[2];
    vector<int> an(n);
    int b = 0;
    while (1<<b != n) b++;
    for (int i = 0; i < b; ++i) {
        vector<int> v(5);
        v[0] = (xors[0]>>i) & 1;
        v[1] = (xors[1]>>i) & 1;
        v[2] = (ands[0]>>i) & 1;
        v[3] = (ands[1]>>i) & 1;
        v[4] = (ands[2]>>i) & 1;
        for (int j = 0; j < 8; ++j) {
            if (v == rule[j]) {
                if (j & 1) {
                    an[0] |= (1<<i);
                }
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        an[i] = xors[i-1] ^ an[i-1];
    }
    cout << "! ";
    for (int i = 0; i < n; ++i) {
        cout << an[i] << ' ';
    }
    cout << endl;
    return 0;
}
