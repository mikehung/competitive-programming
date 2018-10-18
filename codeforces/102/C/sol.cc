#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

string s;
int m, k;
int cnt[30];

bool cmp(int i, int j)
{
    return cnt[i] < cnt[j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> k;
    for (char &ch : s)
        ++cnt[ch-'a'];
    vector<int> idx;
    for (int i = 0; i < 26; ++i)
        idx.emplace_back(i);
    sort(idx.begin(), idx.end(), cmp);
    for (int i = 0; i < 26; ++i) {
        if (!cnt[idx[i]]) continue;
        if (k > cnt[idx[i]]) {
            k -= cnt[idx[i]];
            cnt[idx[i]] = 0;
        } else {
            cnt[idx[i]] -= k;
            break;
        }
    }
    for (int i = 0; i < 26; ++i)
        if (cnt[i]) ++m;
    cout << m << '\n';
    for (char &ch : s) {
        if (cnt[ch-'a']) {
            --cnt[ch-'a'];
            cout << ch;
        }
    }
    cout << '\n';

    return 0;
}
