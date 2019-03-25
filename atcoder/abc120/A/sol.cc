#include <bits/stdc++.h>

using namespace std;


void solve(long long A, long long B, long long C)
{
    cout << min(C, B/A) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long A;
    cin >> A;
    long long B;
    cin >> B;
    long long C;
    cin >> C;
    solve(A, B, C);
    return 0;
}
