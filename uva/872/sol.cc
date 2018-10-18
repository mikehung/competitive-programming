#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int T;
vector<char> cur;
set<string> ans;
set<char> zeros;
map<char, vector<char>> G;
map<char, int> deg;
map<char, bool> visit;

void dfs()
{
    if (cur.size() == G.size()) {
        string a;
        for (auto &x : cur) {
            if (a.empty())
                a += x;
            else {
                a += " ";
                a += x;
            }
        }
        ans.insert(a);
        return;
    }
    for (auto &x : zeros) {
        if (visit[x]) continue;
        cur.push_back(x);
        visit[x] = true;
        for (auto &y : G[x]) {
            if (!--deg[y]) {
                zeros.insert(y);
            }
        }
        dfs();
        cur.pop_back();
        visit[x] = false;
        for (auto &y : G[x]) {
            if (!deg[y]) {
                zeros.erase(y);
            }
            deg[y]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char u;
    string line, cons;
    cin >> T;
    cin.ignore();
    for (int t = 0; t < T; ++t) {
        cur.clear();
        ans.clear();
        zeros.clear();
        G.clear();
        deg.clear();
        visit.clear();
        getline(cin, line);
        {
            getline(cin, line);
            istringstream iss(line);
            while (iss >> u) {
                G[u];
                deg[u] = 0;
            }
        }
        {
            getline(cin, line);
            istringstream iss(line);
            while (iss >> cons) {
                G[cons[0]].push_back(cons[2]);
                ++deg[cons[2]];
            }
        }
        for (auto &kv : deg)
            if (!kv.second)
                zeros.insert(kv.first);
        dfs();
        if (t) cout << '\n';
        if (ans.empty()) {
            cout << "NO\n";
        } else {
            for (auto &x : ans)
                cout << x << '\n';
        }
    }
    return 0;
}
