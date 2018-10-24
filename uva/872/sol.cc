#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    cin >> T;
    while (T--) {
        map<char, vector<char>> G;
        map<char, int> deg;
        vector<char> zero;
        cin.ignore();
        getline(cin, line);
        {
            istringstream iss(line);
            char u;
            while (iss >> u) {
                G[u];
            }
        }
        getline(cin, line);
        {
            istringstream iss(line);
            string con;
            while (iss >> con) {
                G[con[0]].push_back(con[2]);
                deg[con[2]]++;
            }
        }
        for (auto &kv : deg) {
            if (!kv.second)
                zero.push_back(kv.first);
        }
        vector<vector<char>> chains;
        for (auto u : zero) {
            vector<char> chain;
            vis[u] = true;
        }
    }
    return 0;
}
