#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    map<string, int> mp;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        mp[s]++;
    }
    int best = -1;
    vector<string> an;
    for (auto &kv: mp) {
        if (kv.second > best) {
            best = kv.second;
            an.clear();
            an.push_back(kv.first);
        } else if (kv.second == best) {
            an.push_back(kv.first);
        }
    }
    sort(an.begin(), an.end());
    for (auto &s: an) {
        cout << s << '\n';
    }
    return 0;
}
