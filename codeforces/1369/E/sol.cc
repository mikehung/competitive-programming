#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for (auto &it: w) cin >> it;
    vector<vector<int>> friends(m);
    vector<set<int>> needs(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        friends[i].push_back(x);
        friends[i].push_back(y);
        needs[x].insert(i);
        needs[y].insert(i);
    }
    vector<bool> used_food(n), used_friend(m);
    queue<int> q_food;
    for (int i = 0; i < n; ++i) {
        if (needs[i].size() <= w[i]) {
            q_food.push(i);
            used_food[i] = true;
        }
    }
    vector<int> an;
    while (q_food.size()) {
        int foo = q_food.front();
        q_food.pop();
        for (auto fri: needs[foo]) if (!used_friend[fri]) {
            used_friend[fri] = true;
            an.push_back(fri);
            for (auto eat: friends[fri]) if (!used_food[eat]) {
                needs[eat].erase(fri);
                if (!used_food[eat] && needs[eat].size() <= w[eat]) {
                    q_food.push(eat);
                    used_food[eat] = true;
                }
            }
        }
    }
    if (an.size() == m) {
        cout << "ALIVE\n";
        for (int i = m-1; i >= 0; --i) {
            cout << an[i]+1 << ' ';
        }
        cout << '\n';
    } else {
        cout << "DEAD\n";
    }

    return 0;
}
