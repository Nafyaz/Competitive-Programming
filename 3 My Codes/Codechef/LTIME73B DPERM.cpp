#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, d, i, j, pos, flag, ans;
    int a[200010], b[200010];
    scanf("%d", &t);
    while(t--)
    {
        flag = 0;
        ans = 0;
        scanf("%d %d", &n, &d);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b, b+n);
        for(i = 0; i < n; i++)
        {
            if((a[i] - b[i]) % d != 0)
            {
                flag = 1;
                break;
            }
            ans += (a[i] - b[i]) / d;
            a[i] = b[i];
            for(j = i+1; j < n; j++)
            {
                if(b[j] > a[j])
                    pos = find(a + i + 1, a+n, a[j] + d) - a;
                else
                    pos = find(a + i + 1, a+n, a[j] - d) - a;
                if(pos == n)
                {
                    flag = 1;
                    break;
                }
                a[j] = a[j] + d;
            }
            if(flag)
                break;
        }
        if(flag)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
}
