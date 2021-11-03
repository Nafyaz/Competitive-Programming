#include<bits/stdc++.h>
using namespace std;

#define mod 998244353

int a[100005];

int main()
{
    int t, n, i, ans;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
            cin >> a[i];

        ans = 0;
        vector<int> v;

        for(i = n-1; i >= 1; i--)
        {
            ans += i*a[i]/a[i+1];
            v.push_back(a[i]%a[i+1]);
            ans %= mod;
        }
    }
}
