#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, x, mx;
    scanf("%d", &n);
    int a[n];

    for(i = 0; i < n; i++)
    {
        mx = -1;
        for(j = 0; j < n; j++)
        {
            scanf("%d", &x);
            mx = max(mx, x);
        }
        a[i] = mx;
    }
    for(i = 0; i < n - 1; i++)
    {
        if(a[i] == a[i + 1])
        {
            a[i] ++;
            break;
        }
    }
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
}
