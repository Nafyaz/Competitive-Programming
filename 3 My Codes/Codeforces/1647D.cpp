#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, x, d, i, cnt;

    cin >> t;

    while(t--)
    {
        cin >> x >> d;

        cnt = 0;
        for(i = 1; x%d == 0; i++)
        {
            x /= d;

        }
    }
}
