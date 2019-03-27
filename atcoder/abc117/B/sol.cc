#include <bits/stdc++.h>

using namespace std;

const string YES = "Yes";
const string NO = "No";

void solve(long long N, vector<long long> L)
{
    sort(L.begin(), L.end());
    long long x = 0;
    for (int i = 0; i < N-1; ++i) {
        x += L[i];
    }
    cout << (L[N-1] < x ? "Yes" : "No") << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N;
    cin >> N;
    vector<long long> L(N);
    for(int i = 0 ; i < N ; i++){
        cin >> L[i];
    }
    solve(N, move(L));
    return 0;
}
