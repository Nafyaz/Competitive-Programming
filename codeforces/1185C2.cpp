#include<bits/stdc++.h>
using namespace std;
int
int main()
{
    int n, m, i, extra, c;
    scanf("%d %d", &n, &m);

    int a[n+1], s[n+1];
    s[0] = 0;

    for(i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);

        s[i] = s[i - 1] + a[i];
        if(s[i] <= m)
            printf("0 ");
        else
        {
            c = i;
            extra = s[i] - m;


        }
    }
}

