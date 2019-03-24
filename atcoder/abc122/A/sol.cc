#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char c;
    cin >> c;
    if (c == 'A') c = 'T';
    else if (c == 'T') c = 'A';
    else if (c == 'C') c = 'G';
    else c = 'C';
    cout << c << endl;
    return 0;
}
