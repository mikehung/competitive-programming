#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N = 6;
int n, x;
vector<vector<int>> snowflakes;
map<vector<int>, vector<int>> s;
vector<int> v;

bool check(const vector<int> &s1, const vector<int> &s2)
{
    bool eq;
    for (int i = 0; i < N; ++i) {
        eq = true;
        for (int j = 0; j < N; ++j) {
            if (s1[j] != s2[(i+j)%N])
                eq = false;
        }
        if (eq) return true;
    }
    for (int i = 0; i < N; ++i) {
        eq = true;
        for (int j = 0; j < N; ++j) {
            if (s1[j] != s2[(i-j+N)%N])
                eq = false;
        }
        if (eq) return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        v.clear();
        for (int j = 0; j < 6; ++j) {
            cin >> x;
            v.push_back(x);
        }
        snowflakes.push_back(v);
        sort(v.begin(), v.end());
        s[v].push_back(i);
    }
    for (auto &kv: s) {
        auto &indices = kv.second;
        for (int i = 0; i < indices.size(); ++i) for (int j = i+1; j < indices.size(); ++j) {
            if (check(snowflakes[indices[i]], snowflakes[indices[j]])) {
                cout << "Twin snowflakes found.\n";
                return 0;
            }
        }
    }
    cout << "No two snowflakes are alike.\n";

    return 0;
}
