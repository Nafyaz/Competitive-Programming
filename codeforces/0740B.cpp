#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i, j, l, r, ans = 0, s;
    scanf("%d %d", &n, &m);
    int a[n];

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &l, &r);
        s = 0;
        for(j = l-1; j < r; j++)
            s += a[j];

        s > 0? ans += s : ans = ans;
    }
    printf("%d", ans);
}
