#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 3e5 + 5;
int n, avg, a[MAX], cnt[5], d[5][5];
string s, t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    avg = n / 3;
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
        ++cnt[a[i]];
    }
    for (int from = 0; from < 3; ++from) {
        for (int to = 0; to < 3; ++to) if (from != to) {
            if (cnt[from] > avg && cnt[to] < avg) {
                d[from][to] = min(cnt[from]-avg, avg-cnt[to]);
                cnt[from] += d[from][to];
                cnt[to] += d[from][to];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            if (d[1][0]) {
                a[i] = 0;
                d[1][0]--;
            }
        } else if (a[i] == 2) {
            if (d[2][0]) {
                a[i] = 0;
                d[2][0]--;
            } else if (d[2][1]) {
                a[i] = 1;
                d[2][1]--;
            }
        }
    }
    for (int i = n-1; i >= 0; --i) {
        if (a[i] == 1) {
            if (d[1][2]) {
                a[i] = 2;
                d[1][2]--;
            }
        } else if (a[i] == 0) {
            if (d[0][2]) {
                a[i] = 2;
                d[0][2]--;
            } else if (d[0][1]) {
                a[i] = 1;
                d[0][1]--;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i];
    }
    cout << '\n';
    return 0;
}
