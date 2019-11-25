#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, i;
    scanf("%d", &t);

    int n;
    for(i = 1; i <= t; i++)
    {
        scanf("%d", &n);
        if(__builtin_popcount(n) % 2 == 0)
            printf("Case %d: even\n", i);
        else
            printf("Case %d: odd\n", i);
    }
}
