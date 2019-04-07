#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> pv(n+10);
    vector<tuple<int, int, int>> v;
    vector<string> an(m);
    for (int i = 0; i < m; ++i) {
        int p, y;
        cin >> p >> y;
        v.push_back(make_tuple(y, p, i));
    }
    sort(v.begin(), v.end());
    for (auto &tu: v) {
        int y, p, i;
        tie(y, p, i) = tu;
        string pid = to_string(p);
        string id = to_string(++pv[p]);
        while (pid.size() < 6) pid = "0" + pid;
        while (id.size() < 6) id = "0" + id;
        an[i] = pid + id;
    }
    for (int i = 0; i < m; ++i) cout << an[i] << endl;
    return 0;
}
