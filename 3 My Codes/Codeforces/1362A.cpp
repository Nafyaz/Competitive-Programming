#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, a, b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(a > b)
            swap(a, b);
        if(b%a != 0 || ((b/a)&(b/a - 1)) != 0)
            cout << -1 << endl;
        else
        {
            ll cnt = 0;
            while(a != b)
            {
                if((b >> 3) >= a)
                    b >>= 3;
                else if((b >> 2) >= a)
                    b >>= 2;
                else
                    b >>= 1;
                cnt++;
            }

            cout << cnt << endl;
        }
    }
}
