#include <bits/stdc++.h>

using namespace std;

const int MAX = 5212;
int n;
bool a[MAX][MAX];
map<char, int> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 10; ++i) m[i+'0'] = i;
    for (int i = 0; i < 6; ++i) m[i+'A'] = 10+i;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n/4; ++j) {
            char ch;
            cin >> ch;
            int c = m[ch];
            a[i][4*j] = c & 8;
            a[i][4*j+1] = c & 4; 
            a[i][4*j+2] = c & 2;
            a[i][4*j+3] = c & 1;
        }
    }
    int gap = 1;
    while (gap*2 <= n) {
        bool ok = true;
        int jump = gap*2;
        for (int i = 0; i < n && ok; i += jump) {
            for (int j = 0; j < n; j += jump) {
                if (!(a[i][j] == a[i][j+gap] &&
                      a[i][j] == a[i+gap][j] &&
                      a[i][j] == a[i+gap][j+gap])) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) break;
        gap *= 2;
    }
    cout << gap << endl;
    return 0;
}
