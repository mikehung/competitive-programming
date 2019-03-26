#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long) 1e15;

void solve(long long A, long long B, long long Q, vector<long long> s, vector<long long> t, vector<long long> x)
{
    s.insert(s.begin(), -INF), s.push_back(INF);
    t.insert(t.begin(), -INF), t.push_back(INF);
    for (auto q: x) {
        int ps = lower_bound(s.begin(), s.end(), q) - s.begin();
        int pt = lower_bound(t.begin(), t.end(), q) - t.begin();
        long long ans = INF;
        for (int i = -1; i <= 1; ++i) for (int j = -1; j <= 1; ++j) {
            ans = min(ans, abs(q-s[ps+i])+abs(s[ps+i]-t[pt+j]));
            ans = min(ans, abs(q-t[pt+i])+abs(t[pt+i]-s[ps+j]));
        }
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long A;
    cin >> A;
    long long B;
    cin >> B;
    long long Q;
    cin >> Q;
    long long v;
    vector<long long> s;
    for(int i = 0 ; i < A ; i++){
        cin >> v;
        s.push_back(v);
    }
    vector<long long> t;
    for(int i = 0 ; i < B ; i++){
        cin >> v;
        t.push_back(v);
    }
    vector<long long> x(Q);
    for(int i = 0 ; i < Q ; i++){
        cin >> x[i];
    }
    solve(A, B, Q, move(s), move(t), move(x));
    return 0;
}
