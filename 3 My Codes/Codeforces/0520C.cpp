#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll bigmod(ll b, ll p)
{
    if(p == 0)
        return 1;
    ll ret = bigmod(b, p/2);

    ret = (ret * ret)%mod;

    if(p&1)
        ret = (ret * b)%mod;

    return ret;
}

int main()
{
    ll n, cnt[4] = {0}, b, i;
    string s;

    cin >> n >> s;

    for(i = 0; i < n; i++)
    {
        cnt[0] += (s[i] == 'A');
        cnt[1] += (s[i] == 'C');
        cnt[2] += (s[i] == 'G');
        cnt[3] += (s[i] == 'T');
    }

    sort(cnt, cnt+4, greater<ll>());

    b = 1;
    for(i = 0; i < 3; i++)
    {
        if(cnt[i] == cnt[i+1])
            b++;
        else
            break;
    }

    cout << bigmod(b, n);
}
