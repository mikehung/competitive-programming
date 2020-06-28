#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(2*n);
        for (auto &it: a) cin >> it;
        vector<int> odd, even;
        for (int i = 0; i < 2*n; ++i) {
            if (a[i] % 2) {
                odd.push_back(i);
            } else {
                even.push_back(i);
            }
        }
        int cnt = n-1;
        while (cnt--) {
            if (odd.size() >= 2) {
                cout << odd.back()+1 << ' ';
                odd.pop_back();
                cout << odd.back()+1 << '\n';
                odd.pop_back();
            } else {
                cout << even.back()+1 << ' ';
                even.pop_back();
                cout << even.back()+1 << '\n';
                even.pop_back();
            }
        }
    }
    return 0;
}
