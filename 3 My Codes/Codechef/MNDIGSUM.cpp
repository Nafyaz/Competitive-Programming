#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll f(ll n, ll b)
{
    ll ret = 0;
    while(n)
    {
        ret += n%b;
        n /= b;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll q, n, l, r, i, i2, root, b, digsum, minsum;

    cin >> q;

    while(q--)
    {
        cin >> n >> l >> r;

        if(n < l)
        {
            cout << n << "\n";
            continue;
        }

        if(l <= n && n <= r)
        {
            cout << 1 << "\n";
            continue;
        }

        b = r;
        digsum = f(n, b);
        minsum = digsum;

        root = sqrt(n);
        for(i = 2; i <= root; i++)
        {
            if(l <= i && i <= r)
            {
                digsum = f(n, i);

                if(digsum < minsum)
                {
                    minsum = digsum;
                    b = i;
                }
            }

            i2 = n/i;
            if(l <= i2 && i2 <= r)
            {
                digsum = f(n, i2);

                if(digsum < minsum)
                {
                    minsum = digsum;
                    b = i2;
                }
            }
        }

        cout << b << "\n";
    }
}
