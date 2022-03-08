#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    ll t, n, k, i, x, r;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        x = 0;
        for(i = 0; i < n; i++)
        {
            cout << (i^x) << "\n";
            cin >> r;

            x ^= (i^x);

            if(r == 1)
                break;
        }
    }
}
