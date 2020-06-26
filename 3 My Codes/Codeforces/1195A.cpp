#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, i;
    scanf("%d %d", &n, &k);

    int a[k] = {0}, x;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        a[x-1]++;
    }

    int o = 0;
    for(i = 0; i < k; i++)
    {
        if(a[i]&1)
            o++;
    }
    if(n%2 == 0 && o)
        printf("%d", n-1);
    else if(n%2 == 1 && o > 1)
        printf("%d", n-1);
    else
        printf("%d", n);
}
