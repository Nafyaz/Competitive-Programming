#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, i, k, x, ans;

    while(cin >> n)
    {
        if(!n)
            break;

        ans = 0;
        multiset<ll> ms;

        for(i = 0; i < n; i++)
        {
            cin >> k;

            while(k--)
            {
                cin >> x;
                ms.insert(x);
            }

            ans += *(ms.rbegin()) - *(ms.begin());

            ms.erase(ms.begin());
            ms.erase(--ms.end());
        }

        cout << ans << "\n";
    }
}
