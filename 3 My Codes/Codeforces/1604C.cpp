#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100005];

int main()
{
    ll t, n, i, lcm, flag;

    cin >> t;

    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i];

        lcm = 1;
        flag = 1;
        for(i = 0; i < n; i++)
        {
            if(lcm > 1000000009)
                break;
            lcm = lcm*(i+2)/__gcd(lcm, i+2);
            if(a[i] % lcm == 0)
            {
                flag = 0;
                break;
            }
        }

        cout << (flag? "YES\n" : "NO\n");
    }
}
