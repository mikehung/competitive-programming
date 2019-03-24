#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q, l, r;
    string S;
    cin >> N >> Q >> S;
    vector<int> v(N+1);
    for (int i = 1; i < N; ++i) {
        if (S[i-1] == 'A' && S[i] == 'C') v[i+1] = true;
    }
    for (int i = 1; i <= N; ++i) v[i] += v[i-1];
    // for (auto x: v) cerr << x << ' ';
    while (Q--) {
        cin >> l >> r;
        bool off = l && S[l-2] == 'A' && S[l-1] == 'C';
        cout << v[r] - v[l-1] - off << endl;
    }
    return 0;
}
