#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, a, ans = 0;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        ans = ans + 4*a*(i-1);
    }
    printf("%d", ans);
}
