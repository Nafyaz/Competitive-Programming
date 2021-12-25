#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll T, n, k, i, x, ans, sub;

    cin >> T;

    while(T--)
    {
        vector<ll> pos, neg;

        cin >> n >> k;

        for(i = 0; i < n; i++)
        {
            cin >> x;
            if(x > 0)
                pos.push_back(x);
            else if(x < 0)
                neg.push_back(x);
        }

        ans = 0;

        sort(pos.begin(), pos.end(), greater<ll>());
        for(i = 0; i < pos.size(); i += k)
            ans += 2*pos[i];
//        if(i != (ll)pos.size())
//            ans += 2*pos.back();

        sort(neg.begin(), neg.end());
        for(i = 0; i < neg.size(); i += k)
            ans += 2*abs(neg[i]);
//        if(i != (ll)neg.size())
//            ans += 2*abs(neg.back());

        sub = 0;
        if(!pos.empty())
            sub = max(sub, pos[0]);
        if(!neg.empty())
            sub = max(sub, abs(neg[0]));


        cout << ans - sub << "\n";
    }
}
