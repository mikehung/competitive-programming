#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a;
    while (n) {
        a.push_back(n%10);
        n /= 10;
    }
    reverse(a.begin(), a.end());
    int an = 9;
    while (a.size() > 1) {
        an += 10 - a.back();
        do {
            a.pop_back();
            a.back() += 1;
        } while (a.size() && a.back() == 10);
    }
    cout << an << endl;
    return 0;
}
