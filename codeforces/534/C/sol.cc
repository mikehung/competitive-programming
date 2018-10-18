#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N_MAX = 2e5+5;
int n;
long long A, S, nums[N_MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> A;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        S += nums[i];
    }
    long long cnt, mx, mn;
    for (int i = 0; i < n; ++i) {
        cnt = 0;
        mx = A - n + 1;
        mn = A - S + nums[i];
        if (mn > 1)
            cnt += mn - 1;
        if (nums[i] > mx)
            cnt += nums[i] - mx;
        cout << cnt << ' ';
    }
    cout << '\n';

    return 0;
}
