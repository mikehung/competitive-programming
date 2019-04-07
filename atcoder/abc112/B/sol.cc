#include <bits/stdc++.h>

using namespace std;


void solve(long long N, long long T, vector<long long> c, vector<long long> t)
{
    long long an = INT_MAX;
    for (int i = 0; i < N; ++i) if (t[i] <= T) {
        an = min(an, c[i]);
    }
    if (an == INT_MAX) {
        cout << "TLE\n";
    } else {
        cout << an << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N;
    cin >> N;
    long long T;
    cin >> T;
    vector<long long> c(N);
    vector<long long> t(N);
    for(int i = 0 ; i < N ; i++){
        cin >> c[i];
        cin >> t[i];
    }
    solve(N, T, move(c), move(t));
    return 0;
}
