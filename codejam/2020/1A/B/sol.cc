#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int N;
    cin >> N;
    if (N <= 500) {
        for (int i = 1; i <= N; ++i) cout << i << ' ' << 1 << '\n';
    } else {
        int M = N - 33;
        vector<int> bits;
        while (M) {
            bits.push_back(M % 2);
            M /= 2;
        }
        int cur = 1, dir = 0;
        cout << 1 << ' ' << 1 << '\n';
        for (int i = 1; i < bits.size(); ++i) {
            if (bits[i] == 0) {
                cout << i+1 << ' ' << (dir == 0 ? 1 : i+1) << '\n';
                cur += 1;
            } else {
                if (dir == 0) {
                    for (int j = 1; j <= i+1; ++j) {
                        cout << i+1 << ' ' << j << '\n';
                    }
                } else {
                    for (int j = i+1; j >= 1; --j) {
                        cout << i+1 << ' ' << j << '\n';
                    }
                }
                cur += (1<<i);
                dir = 1-dir;
            }
        }
        int i = bits.size() + 1;
        while (cur != N) {
            cout << i << ' ' << (dir == 0 ? 1 : i)  << '\n';
            i++;
            cur++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
