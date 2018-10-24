#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#ifdef DEBUG
    #define debug(args...)  {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // do nothing
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

vector<int> A;

void solve()
{
    int n = A.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    vector<int> B(A.begin(), A.end());
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i-1] == B[j-1] && (i == 0 || A[i-1] != A[i-2])) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    vector<int> res;
    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (A[i-1] == B[j-1]) {
            res.push_back(A[i-1]);
            --i, --j;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(res.begin(), res.end());
    cout << "Max hits: " << res.size() << '\n';
    for (auto x : res)
        cout << x << '\n';
}

int main() 
{
    int T;
    string s;
    cin >> T;
    cin.ignore();
    cin.ignore();
    for (int t = 0; t < T; ++t) {
        if (t) cout << '\n';
        A.clear();
        while (true) {
            getline(cin, s);
            if (s.empty()) {
                solve();
                break;
            } else {
                A.push_back(stoi(s));
            }
        }
    }
}
