#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int a[n];
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        printf("%d\n", min(a[n-2] - 1, n - 2));
    }
}
