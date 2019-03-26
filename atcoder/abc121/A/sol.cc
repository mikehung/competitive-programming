#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    H -= h;
    W -= w;
    cout << H * W << endl;
    return 0;
}
