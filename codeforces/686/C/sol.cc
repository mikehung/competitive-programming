#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int BASE = 7;
int ans, x, n, m, d1 = 1, d2 = 1;
bool visit[BASE];
vector<int> times;

bool check()
{
    for (auto x : times)
        dbg("%d ", x);
    dbg("\n");
    int hour = 0, minute = 0;
    for (int i = 0; i < d1; ++i) {
        hour = hour * 7 + times[i];
    }
    for (int i = d1; i < times.size(); ++i) {
        minute = minute * 7 + times[i];
    }
    return hour < n && minute < m;
}

void go()
{
    if (times.size() == d1 + d2) {
        if (check()) {
            ++ans;
        }
        return;
    }
    for (int i = 0; i < BASE; ++i) {
        if (!visit[i]) {
            visit[i] = true;
            times.push_back(i);
            go();
            visit[i] = false;
            times.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    x = BASE;
    while (x < n) {
        d1++;
        x *= BASE;
    }
    x = BASE;
    while (x < m) {
        d2++;
        x *= BASE;
    }
    dbg("%d %d\n", d1, d2);
    go();
    cout << ans << '\n';
    return 0;
}
