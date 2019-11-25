#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, i, mn;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a);
        a = a/max(i, n-i-1);
        if(i == 0)
            mn = a;
        else
            mn = min(mn, a);
    }

    printf("%d", mn);
}
