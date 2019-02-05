#include <bits/stdc++.h>

using namespace std;
string symbol;

void ask(int x, int y)
{
    cout << "? " << x << " " << y << endl;
    cin >> symbol;
}

void ans(int x)
{
    cout << "! " << x << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string action;
    while (cin >> action) {
        if (action != "start") break;
        int x = 0, y = 1;
        while (true) {
            ask(x, y);
            if (symbol == "e") return 0;
            else if (symbol == "x") break;
            x = y;
            y *= 2;
        }
        int lo = x+1, hi = y;
        while (lo < hi) {
            y = lo + (hi - lo) / 2;
            ask(x, y);
            if (symbol == "e") return 0;
            else if (symbol == "x") {
                hi = y;
            } else {
                lo = y+1;
            }
        }
        ans(lo);
    }
    return 0;
}
