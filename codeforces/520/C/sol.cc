#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9 + 7;
int n;
string s;
vector<char> chars = {'A', 'C', 'T', 'G'};
map<char, int> cnt;

/*
void go(string t)
{
    if (n == (int) t.size()) {
        all_strs.push_back(t);
        return;
    }
    for (auto &ch: chars) {
        go(t+ch);
    }
}

int p(const string &s1, const string &s2)
{
    int n = s1.size(), ans = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
            if (s1[(k+i)%n] == s2[(k+j)%n]) ++ans;
        }
    }
    return ans;
}
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*
    vector<string> tests = {"A", "AA", "AT", "AAA", "AAT", "ATA", "TAA", "ATC",
        "AAAA", "AAAT", "AATT", "AATC", "ATCA", "ATCG",
        "ATCGA", "AATCG", "AATTC", "AATTCC", "AATTCG", "AAATCG", "AAATTT"};
    for (auto &test: tests) {
        vector<string> all_strs;
        map<int, vector<string>> cnt;
        s = test;
        n = test.size();
        go("");
        for (auto &t: all_strs) {
            cnt[p(s, t)].push_back(t);
        }
        cout << s << ": " << cnt.rbegin()->second.size() << '\n';
        cout << "p: " << cnt.rbegin()->first << ", ans: " << cnt.rbegin()->second.size() << ": ";
        for (auto &ans: cnt.rbegin()->second)
            cout << ans << ' ';
        cout << '\n';
    }
    */
    int mx = 0;
    cin >> n >> s;
    for (auto &ch: s) {
        if (++cnt[ch] > mx)
            mx = cnt[ch];
    }
    int c = 0;
    for (auto &kv: cnt) {
        if (kv.second == mx)
            ++c;
    }
    long long ans = 1;
    for (int i = 0; i < n; ++i) {
        ans *= c;
        ans %= MOD;
    }
    cout << ans << '\n';

    return 0;
}
