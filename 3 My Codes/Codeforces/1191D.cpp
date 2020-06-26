#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, sum = 0, i, a;
    scanf("%lld", &n);
    //long long a[n];
    map <long long, long long> mp;

    for(i = 0; i < n; i++)
    {
        scanf("%lld", &a);
        sum += a;
        mp[a] ++;
    }
    if(sum == 0)
    {
        printf("cslnb");
        return 0;
    }

    long long doubles = 0, double_u;
    for(auto u : mp)
    {
        if(u.second >= 3)
        {
            printf("cslnb");
            return 0;
        }
        if(u.second == 2)
        {
            doubles ++;
            double_u = u.first;
        }
        if(doubles >= 2)
        {
            printf("cslnb");
            return 0;
        }
    }

    if(doubles)
    {
        if(mp[double_u - 1] == 1)
        {
            printf("cslnb");
            return 0;
        }
    }

    sum&1 ? printf("cslnb") : printf("sjfnb");
}
