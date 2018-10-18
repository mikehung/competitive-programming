#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int n;
vector<int> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int f = 1;
    while (n) {
        if (n == 3) {
            ans.push_back(f);
            ans.push_back(f);
            ans.push_back(3*f);
            break;
        }
        int x = (n+1)/2;
        while (x--) {
            ans.push_back(f);
        }
        n /= 2;
        f *= 2;
    }
    for (auto x : ans)
        cout << x << ' ';
    cout << '\n';

    return 0;
}
