#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h1, m1, h2, m2;
    scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
    int d = (60*h1+m1 + 60*h2+m2)/2;
    printf("%02d:%02d\n", d/60, d%60);
    return 0;
}
