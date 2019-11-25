#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll i, j, n;
    scanf("%lld", &n);
    ll a[n];

    for(i = 0; i < n; i++)
        scanf("%lld", &a[i]);


    ll c = 0;
    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(a[i] > a[j])
                c++;
        }
    }

    printf("%lld", c);
}
