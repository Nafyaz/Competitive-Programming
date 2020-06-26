#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("A-large-practice.in", "r", stdin);
    freopen("A-large-practice-output.txt", "w", stdout);
    int a[100010];
    int i, n, k, T, caseno = 0, ans, cup, day;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &k);
        for(i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a+1, a+n+1);

        ans = 0, cup = 0, day = 1;
        for(i = 1; i <= n;)
        {
            while(cup < k && day <= a[i])
            {
                cup++;
                i++;
                ans++;
            }

            if(cup >= k)
            {
                cup = 0;
                day++;
            }

            if(day > a[i])
                i++;
        }
        printf("Case #%d: %d\n", ++caseno, ans);
    }
}
