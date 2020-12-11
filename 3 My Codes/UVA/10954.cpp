#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, i, x, ans, sum;
    multiset <ll> ms;

    while(1)
    {
        ms.clear();
        ans = sum = 0;
        cin >> n;

        if(!n)
            break;

        for(i = 0; i < n; i++)
        {
            cin >> x;
            ms.insert(x);
        }

        while(ms.size() > 1)
        {
            sum = (*ms.begin() + *(++ms.begin()));
            ans += sum;
            ms.erase(ms.begin());
            ms.erase(ms.begin());
            ms.insert(sum);
        }

        cout << ans << "\n";
    }
}
