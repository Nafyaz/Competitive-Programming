#include<bits/stdc++.h>
using namespace std;

int bigmod(int a, int b, int mod)
{
    if(b == 0)
        return 1;
    int res = bigmod(a, b>>1, mod);
    res = (res*res)%mod;
    if(b&1)
        res = (res*a)%mod;
    return res;
}

int main()
{
    int n, flag, ans = 0;
    cin >> n;
    for(int x = 1; x < n; x++)
    {
        flag = 1;
        for(int i = 1; i < n-1; i++)
        {
            if(bigmod(x, i, n) == 1)
                flag = 0;
        }
        if(flag)
            ans++;
    }
    cout << ans;
}

