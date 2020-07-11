#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> cnt, a;

int get_mex()
{
    int an = 0;
    while (cnt[an] > 0) an++;
    return an;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cnt = vector<int>(1005);
        a = vector<int>(n);
        for (auto &it: a) cin >> it;
        for (int i = 0; i < n; ++i) {
            cnt[a[i]]++;
        }
        vector<int> an;
        while (true) {
            int mex = get_mex();
            if (mex < n) {
                cnt[a[mex]]--;
                cnt[mex]++;
                a[mex] = mex;
                an.push_back(mex);
            }
            
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                if (a[i] != i) {
                    ok = false;
                    if (mex == n) {
                        cnt[a[i]]--;
                        cnt[n]++;
                        a[i] = n;
                        an.push_back(i);
                    }
                    break;
                }
            }
            if (ok) break;
        }

        cout << an.size() << '\n';
        if (an.size()) {
            for (auto x: an) cout << x+1 << ' ';
            cout << '\n';
        }
    }
    return 0;
}
