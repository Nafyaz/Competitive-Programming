#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll n, l, r, x;

    cin >> n;

    while(n--)
    {
        cin >> l >> r;

        x = 1;

        while((l|x) <= r)
        {
            l |= x;
            x <<= 1LL;
        }
        cout << l << endl;
    }
}
