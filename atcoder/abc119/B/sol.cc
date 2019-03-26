#include <bits/stdc++.h>

using namespace std;


void solve(long long N, vector<long double> x, vector<string> u)
{
    long double ans = 0;
    for (int i = 0; i < N; ++i) {
        if (u[i] == "JPY")
            ans += x[i];
        else
            ans += x[i] * (long double) 380000.0;
    }
    cout << fixed << setprecision(12) << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N;
    cin >> N;
    vector<long double> x(N);
    vector<string> u(N);
    for(int i = 0 ; i < N ; i++){
        cin >> x[i];
        cin >> u[i];
    }
    solve(N, move(x), move(u));
    return 0;
}
