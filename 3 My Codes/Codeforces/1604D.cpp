#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, x, y, n;

    cin >> t;

    while(t--)
    {
        cin >> x >> y;

        if(x > y)
            n = x+y;
        else if(y%x == 0)
            n = x;
        else
            n = y/x*x + (y%x)/2;

        cout << n << "\n";
    }
}
