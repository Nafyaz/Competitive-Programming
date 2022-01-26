#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll t[100005];
ll p[100005];
set<pair<ll, ll>> s;

int main()
{
    ll n, k, x, i, speed, remTime;

    cin >> n >> k >> x >> p[0];

    for(i = 1; i <= n; i++)
    {
        cin >> speed;
        s.insert({speed, i});
    }
    for(i = 1; i <= k; i++)
        cin >> t[i];
    for(i = 1; i <= k; i++)
        cin >> p[i];

    for(i = 0; i <= k; i++)
    {
        while(!s.empty())
        {
            auto it = s.end();
            it--;

            remTime = p[i] - t[i];

            if((*it).ff * remTime >= x)
                s.erase(it);
            else
                break;
        }
    }

    cout << n - s.size();
}
