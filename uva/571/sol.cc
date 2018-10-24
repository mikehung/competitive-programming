#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 1005;
int visit[MAX][MAX];
pair<int, int> parent[MAX][MAX];
string msg[MAX][MAX];
pair<int, int> p;
queue<pair<int, int>> Q;
int ca, cb, a, b, na, nb, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    pair<int, int> par;
    while (cin >> ca >> cb >> n) {
        for (int i = 0; i < MAX; ++i) {
            memset(visit[i], 0, sizeof(visit[i]));
        }
        while (!Q.empty())
            Q.pop();

        Q.push(make_pair(0, 0));
        visit[0][0] = 1;
        while (!Q.empty()) {
            p = Q.front();
            a = p.first;
            b = p.second;
            Q.pop();
            if (b == n) {
                vector<string> ans;
                ans.push_back("success");
                while (a || b) {
                    ans.push_back(msg[a][b]);
                    p = parent[a][b];
                    a = p.first;
                    b = p.second;
                }
                for (int i = ans.size()-1; i >= 0; --i)
                    puts(ans[i].c_str());
                break;
            }
            if (a != ca && !visit[ca][b]) {
                par = make_pair(ca, b);
                Q.push(par);
                visit[ca][b] = 1;
                parent[ca][b] = p;
                msg[ca][b] = "fill A";
            }
            if (b != cb && !visit[a][cb]) {
                par = make_pair(a, cb);
                Q.push(par);
                visit[a][cb] = 1;
                parent[a][cb] = p;
                msg[a][cb] = "fill B";
            }
            if (a && !visit[0][b]) {
                par = make_pair(0, b);
                Q.push(par);
                visit[0][b] = 1;
                parent[0][b] = p;
                msg[0][b] = "empty A";
            }
            if (b && !visit[a][0]) {
                par = make_pair(a, 0);
                Q.push(par);
                visit[a][0] = 1;
                parent[a][0] = p;
                msg[a][0] = "empty B";
            }
            if (a && b != cb) {
                na = max(0, a+b-cb);
                nb = min(cb, a+b);
                if (!visit[na][nb]) {
                    par = make_pair(na, nb);
                    Q.push(par);
                    visit[na][nb] = 1;
                    parent[na][nb] = p;
                    msg[na][nb] = "pour A B";
                }
            }
            if (b && a != ca) {
                na = min(ca, a+b);
                nb = max(0, a+b-ca);
                if (!visit[na][nb]) {
                    par = make_pair(na, nb);
                    Q.push(par);
                    visit[na][nb] = 1;
                    parent[na][nb] = p;
                    msg[na][nb] = "pour B A";
                }
            }
        }
    }
    return 0;
}
