#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, l, r, i, j, xor, xorEven, xorOdd;

    cin >> t;

    while(t--)
    {
        cin >> l >> r;

        for(i = 0; i <= r; i++)
            cin >> a[i];

        xor = xorEven = xorOdd = 0;
        for(i = 0; i <= r; i++)
        {
            xor ^= a[i];

            if(a[i]&1)
                xorOdd ^= a[i];
            else
                xorEven ^= a[i];
        }

        if(r%4 == 1)
        {
            cout << (xor ^ 1) << "\n";
            continue;
        }
        else if(r%4 == 3)
        {
            cout << xor << "\n";
            continue;
        }


    }
}
