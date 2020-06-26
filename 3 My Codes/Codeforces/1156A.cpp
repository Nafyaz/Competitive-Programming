#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, prev, ans = 0;
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 1; i < n; i++)
    {
        if(a[i]*a[i - 1] == 6)
        {
            printf("Infinite");
            return 0;
        }
        if(a[i]*a[i - 1] == 2)
            ans += 3;
        if(a[i]*a[i - 1] == 3)
            ans += 4;

        if(i >= 2 && a[i-2] == 3 && a[i-1] == 1 && a[i] == 2)
            ans --;
    }
    printf("Finite\n%d", ans);
}
