#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &v: a) cin >> v;
    int last = 0, i = 0, j = n-1;
    char L = 'L', R = 'R';
    string an;
    while (i < j) {
        bool use_L;
        if (last >= a[i] && last >= a[j]) break;
        if (last >= a[i] && last < a[j]) {
            use_L = false;
        } else if (last >= a[j] && last < a[i]) {
            use_L = true;
        } else {
            if (a[i] < a[j]) {
                use_L = true;
            } else if (a[i] > a[j]) {
                use_L = false;
            } else {
                int l = i, r = j;
                while (l < r && a[l+1] > a[l]) ++l;
                while (l < r && a[r-1] > a[r]) --r;
                use_L = l-i > j-r;
            }
        }
        if (use_L) {
            an.push_back(L);
            last = a[i++];
        } else {
            an.push_back(R);
            last = a[j--];
        }
    }
    if (i == j && a[i] > last) {
        an.push_back(L);
    }
    cout << an.size() << endl << an << endl;
    return 0;
}
