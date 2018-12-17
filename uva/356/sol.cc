#include <bits/stdc++.h>

using namespace std;

bool check(int x, int y, int n, double r)
{
    return (x-n)*(x-n) + (y-n)*(y-n) <= r*r;
}

int main()
{
    int n;
    vector<int> a;
    while (scanf("%d", &n) == 1) {
        a.push_back(n);
    }
    int partial, complete;
    bool b0, b1, b2, b3;
    for (int i = 0; i < (int) a.size(); ++i) {
        n = a[i];
        partial= 0, complete = 0;
        for (int r = 0; r < 2*n; ++r) for (int c = 0; c < 2*n; ++c) {
            b0 = check(r, c, n, (2*n-1)/2.);
            b1 = check(r, c+1, n, (2*n-1)/2.);
            b2 = check(r+1, c, n, (2*n-1)/2.);
            b3 = check(r+1, c+1, n, (2*n-1)/2.);
            if (b0 && b1 && b2 && b3)
                ++complete;
            else if (b0 || b1 || b2 || b3)
                ++partial;
        }
        if (i) printf("\n");
        printf("In the case n = %d, %d cells contain segments of the circle.\n"
               "There are %d cells completely contained in the circle.\n", n, partial, complete);
    }
    return 0;
}
