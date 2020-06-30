#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, a, b, c;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        ll x = -1, y = -1;
        if(a < c)
            x = 1;
        if(a*b > c)
            y = b;

        cout << x << " " << y << endl;
    }
}
