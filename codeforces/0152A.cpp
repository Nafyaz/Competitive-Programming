#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    char s[110];
    int a[n][m];

    FORAB(i, 0, n)
    {
        scanf("%s", s);
        FORAB(j, 0, m)
        {
            a[i][j] = s[j] - '0';
        }
    }

    int high[m] = {0};//highest mark on ith subject is on high[i]
    FORAB(i, 0, m)
    {
        FORAB(j, 0, n)
        {
            high[i] = max(high[i], a[j][i]);
        }
    }
    int suc[n];
    FORAB(i, 0, n)
        suc[i] = m;


    FORAB(i, 0, n)
    {
        FORAB(j, 0, m)
        {
            if(a[i][j] != high[j])
                suc[i]--;
        }
    }

    int ans = 0;
    FORAB(i, 0, n)
    {
        if(suc[i] != 0)
            ans++;
    }
    printf("%d", ans);
}
