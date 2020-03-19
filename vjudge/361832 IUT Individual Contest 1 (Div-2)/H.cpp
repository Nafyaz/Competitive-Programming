#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, g, i, s, r, ans = 0;
    cin >> n >> g;
    vector<ll> diff;

    for(i = 0; i < n; i++)
    {
        cin >> s >> r;
        if(s > r)
            ans += 3;
//        else if(s == r)
//        {
//            ans++;
//            diff.push_back(r-s);
//        }
        else
        {

            diff.push_back(r-s);
        }
    }

    sort(diff.begin(), diff.end());

    for(i = 0; i < diff.size(); i++)
    {
//        if(diff[i] == 0 && g >= 1)
//        {
//            ans += 2;
//            g--;
//        }
        if(g >= diff[i] + 1)
        {
            ans += 3;
            g -= diff[i] + 1;
        }
        else if(g == diff[i])
        {
            ans++;
            g -= diff[i];
        }
    }

    cout << ans;
}
