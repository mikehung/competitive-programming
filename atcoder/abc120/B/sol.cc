#include <bits/stdc++.h>

using namespace std;


void solve(long long A, long long B, long long K)
{
    vector<int> v;
    for (int i = 1; i <= min(A, B); ++i) {
        if ((A % i) == 0 && (B % i) == 0) v.push_back(i);
    }
    reverse(v.begin(), v.end());
    cout << v[K-1] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long A;
    cin >> A;
    long long B;
    cin >> B;
    long long K;
    cin >> K;
    solve(A, B, K);
    return 0;
}
