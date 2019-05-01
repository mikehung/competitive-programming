#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, B, A, i, a, b;
    cin >> N >> A >> B;
    a = A, b = B;
    vector<int> v(N);
    for (auto &x: v) cin >> x;
    for (i = 0; i < N && (a || b); ++i) {
        if (!a) {
            --b;
        } else if (!b) {
            --a;
            if (v[i]) ++b;
        } else {
            if (b == B) {
                --b;
            } else if (!v[i]) {
                --b;
            } else {
                --a, ++b;
            }
        }
        b = min(b, B);
    }
    cout << i << endl;
    return 0;
}
