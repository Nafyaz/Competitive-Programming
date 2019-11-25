#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, x[1000010];

ll maxsum()
{
    ll sum = 0, flag = 0, mx = INT_MIN, mxsum = INT_MIN;
    for(ll i = 0; i < n; i++)
    {
        mx = max(mx, x[i]);
        sum += x[i];

        if(sum < 0)
            sum = 0;
        else
        {
            flag = 1;
            mxsum = max(mxsum, sum);
        }
    }

    if(flag)
        return mxsum;
    else
        return mx;
}


int main()
{
    ll i, a, b;
    scanf("%lld %lld %lld", &n, &a, &b);

    for(i = 0; i < n; i++)
        scanf("%lld", &x[i]);

    if(a == 0)
    {
        printf("%lld", b);
        return 0;
    }

    else if(a < 0)
    {
        for(i = 0; i < n; i++)
            x[i] *= -1;
    }

    if(a > 0)
        printf("%lld", a*maxsum() + b);
    else
        printf("%lld", -a*maxsum() + b);
}
