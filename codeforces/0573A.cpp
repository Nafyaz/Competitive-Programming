#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i;
    scanf("%d", &n);
    long long a[n], mn = 1000000010, mx = 0, x;

    for(i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        while(!(a[i]&1)) a[i] = a[i] >> 1;
        while(a[i]%3 == 0) a[i] /= 3;
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    if(mx == mn)
        printf("Yes");
    else
        printf("No");
}
