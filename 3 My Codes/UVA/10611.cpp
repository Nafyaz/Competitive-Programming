#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, q, i, h[50009], x, l, r;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> h[i];

    cin >> q;
    for(i = 0; i < q; i++)
    {
        cin >> x;
        l = lower_bound(h, h+n, x) - h;

        if(l == 0)
            cout << "X ";
        else
            cout << h[l-1] << " ";

        r = upper_bound(h, h+n, x) - h;
        if(r == n)
            cout << "X\n";
        else
            cout << h[r] << "\n";
    }
}
