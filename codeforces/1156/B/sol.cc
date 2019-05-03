#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> g;

void dfs(int v, set<int> &s, vector<int> &seq)
{
    for (auto &u: g[v]) if (!s.count(u)) {
        seq.push_back(u);
        s.insert(u);
        dfs(u, s, seq);
        break;
    }
}

void calc()
{
    string s;
    cin >> s;
    int n = s.size();
    map<int, int> cnt;
    g.clear();
    for (int i = 0; i < n; ++i) {
        cnt[s[i]-'a']++;
    }
    if (cnt.size() == 1) {
        cout << s << endl;
        return;
    }
    for (auto &kv1: cnt) for (auto &kv2: cnt) {
        if (kv1.first != kv2.first && abs(kv1.first - kv2.first) != 1) {
            g[kv1.first].push_back(kv2.first);
            g[kv2.first].push_back(kv1.first);
        }
    }
    for (auto &kv1: cnt) {
        vector<int> seq;
        set<int> s;
        seq.push_back(kv1.first);
        s.insert(kv1.first);
        dfs(kv1.first, s, seq);
        if (seq.size() == cnt.size()) {
            for (auto x: seq) {
                while (cnt[x]--) {
                    cout << (char) (x+'a');
                }
            }
            cout << endl;
            return;
        }
    }
    cout << "No answer\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        calc();
    }
    return 0;
}
