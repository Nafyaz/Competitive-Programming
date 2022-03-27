#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll x, i, a[13] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    for(x = 0; x <= 20; x++)
    {
        cout << setw(3) << x << ":";
        for(i = 0; i < 13; i++)
            cout << setw(4) << (a[i]^x);
        cout << "\n";
    }

    cout << (2^3^4^5^6^7);
}
