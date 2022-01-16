#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, i, a;

    cin >> n;

    vector<ll> ones;
    for(i = 0; i < n; i++)
    {
        cin >> a;

        if(a == 1)
            ones.push_back(i);
    }

    if(ones.empty())
    {
        cout << 0;
        return 0;
    }

    ll ans = 1;
    for(i = 1; i < ones.size(); i++)
        ans *= (ones[i] - ones[i-1]);

    cout << ans;
}

