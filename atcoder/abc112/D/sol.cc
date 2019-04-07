#include <bits/stdc++.h>

using namespace std;

long long N, M, an;

bool check(long long v)
{
    return M / v >= N;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (long long i = 1; i*i <= M; ++i) if (M % i == 0) {
        if (check(i)) an = max(an, i);
        if (check(M/i)) an = max(an, M/i);
    }
    cout << an << endl;
    return 0;
}

