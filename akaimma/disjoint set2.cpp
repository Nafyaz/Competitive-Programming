#include<bits/stdc++.h>
using namespace std;

int f(int *p, int x)
{
    if(p[x] == x)
        return x;
    else
        return p[x] = f(p, f(p, p[x]));
}
int main()
{
    int n, m, i, a, b, u, v;
    scanf("%d %d", &n, &m);

    int pr[n+1];
    for(i = 1; i <= n; i++)
        pr[i] = i;

    while(m--)
    {
        scanf("%d %d", &a, &b);
        u = f(pr, a);
        v = f(pr, b);
        pr[v] = u;
        for(i = 1; i <= n; i++)
            printf("%d ", pr[i]);
        printf("\n");
        for(i = 1; i <= n; i++)
                printf("%d ", f(pr, i));
        printf("\n");
    }
}
