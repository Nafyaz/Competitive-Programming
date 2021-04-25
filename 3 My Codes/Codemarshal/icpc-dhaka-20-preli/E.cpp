#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[30009];
vector<ll> pos, neg;

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    ll T, caseno = 0, n, i, mx, sum, moves;

    cin >> T;

    while(T--)
    {
        cin >> n;

        sum = 0;
        mx = INT_MIN;
        pos.clear();
        neg.clear();

        for(i = 0; i < n; i++)
        {
            cin >> a[i];

            if(a[i] >= 0)
            {
                pos.push_back(i);
                sum += a[i];
            }
            else
                neg.push_back(i);

            mx = max(mx, a[i]);
        }

        if(mx <= 0)
        {
            cout << "Case " << ++caseno << ": " << mx << " 0\n";
            continue;
        }

        ll st = 0, ed = pos.size() - 1;
        ll poscnt = 0, mxposcnt = -1;

        for(i = st; i <= ed; i++)
            poscnt += (a[i] >= 0);

        mxposcnt = max(mxposcnt, poscnt);
        st++;
        ed++;

        while(ed < n)
        {
            if(a[ed] >= 0)
                poscnt++;
            if(a[st-1] >= 0)
                poscnt--;


            mxposcnt = max(mxposcnt, poscnt);

            st++;
            ed++;
        }

        moves = pos.size() - mxposcnt;

        cout << "Case " << ++caseno << ": " << sum << " " << moves << "\n";
    }
}
