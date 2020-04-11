#include<bits/stdc++.h>
using namespace std;

int a[100];

int rec(int n, int x)
{
    if (n == -1)
        return n;
    if(a[n] == x)
        return n;
    return rec(n - 1, x);
}
int main()
{
    int i, n, q, b;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &q);
    for(i = 0; i < q; i++)
    {
        scanf("%d", &b);
        printf("%d\n", rec(n-1, b));
    }
}
