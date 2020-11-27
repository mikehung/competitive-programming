#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> xors(n-1), same;
    map<int, vector<int>> mp;

    for (int i = 0; i < n-1; ++i) {
        cout << "XOR " << 1 << ' ' << i+2 << endl;
        cin >> xors[i];
        mp[xors[i]].push_back(i);
    }

    int an0 = 0;
    auto ask = [&](int x){
        cout << "AND " << 1 << ' ' << x+2 << endl;
        int r;
        cin >> r;
        for (int i = 0; i < 20; ++i) {
            if (((xors[x]>>i)&1) == 0) {
                an0 |= (r&(1<<i));
            }
        }
    };

    if (mp.count(0)) {
        ask(mp[0][0]);
    } else {
        for (auto kv: mp) {
            if (kv.second.size() >= 2) {
                cout << "AND " << kv.second[0]+2 << ' ' << kv.second[1]+2 << endl;
                int r;
                cin >> r;
                an0 = xors[kv.second[0]] ^ r;
                break;
            }
            if (mp.count((n-1)^kv.first)) {
                ask(kv.second[0]);
                ask(mp[(n-1)^kv.first][0]);
                break;
            }
        }
    }

    cout << "! " << an0;
    for (int i = 0; i < n-1; ++i) {
        cout << ' ' << (an0 ^ xors[i]);
    }
    cout << endl;
    return 0;
}
