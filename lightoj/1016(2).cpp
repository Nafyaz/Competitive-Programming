#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, caseno = 0, i, j, w, n, c[50009], x, y;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &w);
        for(i = 0; i < n; i++)
        {
            scanf("%d %d", &x, &y);
            c[i] = y;
        }
        sort(c, c+n);

        int st, ed, ans = 0;
        for(i = 0; i < n;)
        {
            st = c[i];
            while(c[i] <= st+w)
                i++;
            ans++;
        }

        printf("Case %d: %d\n", ++caseno, ans);
    }
}

