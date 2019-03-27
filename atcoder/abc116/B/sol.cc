#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> s;
    s.insert(n);
    for (int i = 2; ;++i) {
        if (n & 1) n = 3*n+1;
        else n /= 2;
        if (s.count(n)) {
            cout << i << endl;
            return 0;
        }
        s.insert(n);
    }
    return 0;
}
