#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> idx(26);
    for (int i = n-1; i >= 0; --i) {
        idx[s[i]-'a'].push_back(i);
    }

    reverse(s.begin(), s.end());
    ordered_set se;
    ll an = 0;
    for (int i = 0; i < n; ++i) {
        int id = idx[s[i]-'a'].back();
        idx[s[i]-'a'].pop_back();
        an += id - se.order_of_key(id);
        se.insert(id);
    }
    cout << an << '\n';
    return 0;
}
