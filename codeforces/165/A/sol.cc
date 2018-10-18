#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 235;
int n, PL[MAX], PR[MAX];
map<int, vector<int>> L, R;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> PL[i] >> PR[i];
        L[PL[i]].push_back(PR[i]);
        R[PR[i]].push_back(PL[i]);
    }
    for (auto &kv : L)
        sort(kv.second.begin(), kv.second.end());
    for (auto &kv : R)
        sort(kv.second.begin(), kv.second.end());

    int ans = 0, rmn, rmx, lmn, lmx;
    for (int i = 0; i < n; ++i) {
        rmn = L[PL[i]].front();
        rmx = L[PL[i]].back();
        lmn = R[PR[i]].front();
        lmx = R[PR[i]].back();
        if (rmn < PR[i] && PR[i] < rmx && lmn < PL[i] && PL[i] < lmx)
            ++ans;
    }
    cout << ans << '\n';

    return 0;
}
