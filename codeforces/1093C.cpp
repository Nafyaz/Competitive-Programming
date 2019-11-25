#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, n;
    scanf("%d", &n);
    long long b[n/2], a[n], x, y;
    for(i = 0; i < n/2; i++)
        scanf("%lld", &b[i]);

    a[0] = 0;
    a[n - 1] = b[0];
    //printf("%d %d", b[n/2 -1]/2, b[n/2 - 1]);
    for(i = 1; i < n/2; i++)
    {
        x = min(b[i], a[n - i]);
        y = max(a[i - 1], b[i] - x);
        a[i] = y;
        a[n-i - 1] = b[i] - y;
    }
    for(i = 0; i < n; i++)
        printf("%lld ", a[i]);
}
