#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, x, y, i, a, alice, bob;

    cin >> t;

    while(t--)
    {
        cin >> n >> x >> y;

        alice = (x & 1);
        bob = (alice ^ 1);

        for(i = 0; i < n; i++)
        {
            cin >> a;

            alice ^= (a&1);
            bob ^= (a&1);
        }

        if(alice == (y & 1))
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
}
