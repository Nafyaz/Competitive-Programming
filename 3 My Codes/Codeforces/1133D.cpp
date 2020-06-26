#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i;
    scanf("%d", &n);
    int a[n], b[n];
    map <long double, int> mp;

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);

    int z = 0;
    for(i = 0; i < n; i++)
    {
        if(a[i] == 0 && b[i] == 0)
            z++;
        if(a[i] != 0)
            mp[(long double)b[i]/a[i]] ++;
    }

    int mx = z;
    for(auto u : mp)
        mx = max(mx, u.second+z);

    printf("%d", mx);
}
