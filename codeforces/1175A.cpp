#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
    ll n, k, ans;
    int t;
    cin >> t;
    while(t--)
    {
        ans = 0;
        cin >> n >> k;
        while(n)
        {
            if(n%k == 0)
            {
                ans++;
                n /= k;
            }

            ans += n%k;
            n = n/k*k;
        }

        cout << ans << endl;
    }
}

