#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, x;
    scanf("%d", &n);
    int a[n+1], b[n+1];

    for(i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        a[x] = i;
    }
    for(i = 1; i <= n; i++)
        scanf("%d", &b[i]);


    for(i = 1; i <= n; i++)
        printf("%d ", a[b[i]]);
}
