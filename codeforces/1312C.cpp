#include<bits/stdc++.h>
using namespace std;
#define ll long long

bitset<65> b;

bool kbase(ll x, ll k)
{
    ll i = 0;

    while(x)
    {
        if(x%k > 1)
            return 0;
        if(b[i] && x%k)
            return 0;

        b[i] = b[i] | x%k;
        i++;
        x /= k;
    }

    return 1;
}

int main()
{
    ll t, n, k, a, i, j, flag;

    cin >> t;
    while(t--)
    {
        flag = 1;
        b = 0;
        cin >> n >> k;
        for(i = 0; i < n; i++)
        {
            cin >> a;

            if(kbase(a, k) == 0)
                flag = 0;

//            cout << "b: " << b << endl;
//            if(flag)
//                p[i] = b;
        }

        cout << (flag? "YES" : "NO") << endl;
    }
}
