#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, o = 0, e = 0;
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i] & 1)
            o++;
        else
            e++;
    }
    if(o && e)
        sort(a, a+n);

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
}
