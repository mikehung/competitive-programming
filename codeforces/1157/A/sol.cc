#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    set<int> s;
    cin >> n;
    while (!s.count(n)) {
        s.insert(n);
        n += 1;
        while (n % 10 == 0) n /= 10;
    }
    cout << s.size() << endl;
    return 0;
}
