#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, a, b, aPower, flag;

    cin >> t;

    while(t--)
    {
        cin >> n >> a >> b;

        if(a == 1)
        {
            cout << ((n-1)%b == 0? "Yes\n" : "No\n");
            continue;
        }

        flag = 0;
        for(aPower = 1; aPower <= n && !flag; aPower *= a)
        {
            if((n - aPower)%b == 0)
                flag = 1;
        }

        cout << (flag? "Yes\n" : "No\n");
    }
}
