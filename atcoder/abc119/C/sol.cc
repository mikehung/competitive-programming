#include <bits/stdc++.h>

using namespace std;

int N, A, B, C, l[10], ans = 1e9;

void calc(int i, int a, int b, int c, int merge)
{
    if (i == N) {
        if (a != 0 && b != 0 && c != 0)
            ans = min(ans, abs(A-a) + abs(B-b) + abs(C-c) + merge - 30);
        return;
    }
    calc(i+1, a, b, c, merge);
    calc(i+1, a+l[i], b, c, merge+10);
    calc(i+1, a, b+l[i], c, merge+10);
    calc(i+1, a, b, c+l[i], merge+10);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> A >> B >> C;
    for (int i = 0; i < N; ++i) cin >> l[i];
    calc(0, 0, 0, 0, 0);
    cout << ans << endl;

    return 0;
}
