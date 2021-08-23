#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll presum[100005];

ll is_pal(ll n)
{
    ll n1 = n, n2 = 0;

    while(n)
    {
        n2 *= 10;
        n2 += (n%10);
        n /= 10;
    }

    if(n1 == n2)
        return n1;
    else
        return 0;
}

int main()
{
    ll t, i, l, r;

    for(i = 1; i < 100005; i++)
    {
        presum[i] = presum[i-1] + is_pal(i);
    }

    cin >> t;

    while(t--)
    {
        cin >> l >> r;

        cout << presum[r] - presum[l-1] << "\n";
    }
}
