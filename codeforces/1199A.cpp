#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, y, i, j;
    scanf("%d %d %d", &n, &x, &y);
    int a[n+1];

    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    int flag;

    for(i = 1; i <= n; i++)
    {
        flag = 0;
        for(j = max(1, i - x); j < i; j++)
        {
            if(a[i] > a[j])
                flag = 1;
        }
        for(j = i+1; j <= min(n, i+y); j++)
        {
            if(a[i] > a[j])
                flag = 1;
        }
        if(!flag)
        {
            printf("%d", i);
            return 0;
        }
    }
}
