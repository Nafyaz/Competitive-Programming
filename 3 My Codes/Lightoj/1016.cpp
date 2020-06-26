#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, w, T, caseno = 0;
    int ans, x, y[50010], i;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &w);
        for(i = 0; i < n; i++)
            scanf("%d %d", &x, &y[i]);
        sort(y, y+n);

        ans = 0;

        i = 0;
        while(i < n)
        {
            i = upper_bound(y, y+n, y[i] + w) - y;
//            printf("%d ", i);
            ans++;
        }

        printf("Case %d: %d\n", ++caseno, ans);
    }
}
