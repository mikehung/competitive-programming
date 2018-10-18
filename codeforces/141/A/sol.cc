#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 300;
int a[MAX];

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    for (char ch : s1)
        a[(int) ch]++;
    for (char ch : s2)
        a[(int) ch]++;
    for (char ch : s3)
        a[(int) ch]--;
    bool flag = true;
    for (int i = 0; i < MAX; ++i) {
        if (a[i])
            flag = false;
    }
    if (flag)
        puts("YES");
    else
        puts("NO");

    return 0;
}
