#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[10009];
int main()
{
    ll t, i, z, psum, nsum;
    cin >> t;

    while(t--)
    {
        ll n, k;
        cin >> n >> k;

        psum = nsum = z = 0;
        vector<ll> neg, pos;

        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i] > 0)
            {
                pos.push_back(a[i]);
                psum += a[i];
            }
            else if(a[i] == 0)
                z++;
            else
            {
                neg.push_back(-a[i]);
                nsum -= a[i];
            }
        }

        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());

//        for(auto u : pos)
//            cout << u << " ";
//        cout << endl;
//        for(auto u : neg)
//            cout << u << " ";
//        cout << endl;

        ll sum = 0;
        if(k <= neg.size())
        {
            reverse(neg.begin(), neg.end());
            for(i = 0; i < neg.size(); i++)
            {
                if(i < k)
                    sum += neg[i];
                else
                    sum -= neg[i];
            }
            cout << sum + psum << endl;
        }

        else if(k > neg.size() && z)
        {
            cout << psum + nsum << endl;
        }

        else
        {
            sum = psum + nsum;
            k -= neg.size();
            ll x = 1000;
            if(pos.size() > 0)
                x = min(x, pos[0]);
            if(neg.size() > 0)
                x = min(x, neg[0]);

            cout << sum - 2*(k%2)*x << endl;
        }
    }
}
