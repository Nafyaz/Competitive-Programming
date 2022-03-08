#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];

class op
{
public:
    ll x, y, z;

    op(ll px, ll py, ll pz)
    {
        x = px;
        y = py;
        z = pz;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, i, x, y, z, flag;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
            cin >> a[i];

        if(a[n-1] > a[n])
        {
            cout << "-1\n";
            continue;
        }

        vector<op> ans;
        flag = 1;
        z = n;
        for(y = n-1; y >= 2 && flag; y--)
        {
            x = y-1;
            if(a[x] > a[y] && a[y] - a[z] > a[y])
            {
                flag = 0;
                break;
            }

            if(a[x] > a[y] - a[z])
            {
                a[x] = a[y] - a[z];
                ans.push_back(op(x, y, z));
            }
        }

        if(!flag)
        {
            cout << "-1\n";
            continue;
        }

        cout << ans.size() << "\n";
        for(auto u : ans)
            cout << u.x << " " << u.y << " " << z << "\n";
    }
}
