#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll c[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, i, n, flag;

    cin >> t;

    while(t--)
    {
        cin >> n;

        vector<ll> ones;
        for(i = 0; i < n; i++)
        {
            cin >> c[i];
            if(c[i] == 1)
                ones.push_back(i);
        }

        if(ones.size() != 1)
        {
            cout << "No\n";
            continue;
        }

        rotate(c, c+ones[0], c+n);

        flag = 1;
        for(i = 1; i < n; i++)
        {
            if(c[i] - c[i-1] > 1)
            {
                flag = 0;
                break;
            }
        }

        cout << (flag? "Yes\n" : "No\n");
    }
}
