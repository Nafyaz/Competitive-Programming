#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;

ll query(ll x)
{
    cout << "1 " << n-x+1 << " 1 ";
    ll i, ret;
    for(i = x; i <= n; i++)
        cout << i << " ";
    cout << "\n";

    cin >> ret;

    return ret;
}

int main()
{
    ll t, i, ans, low, high, mid, dis, farNode;

    cin >> t;

    while(t--)
    {
        cin >> n;

        ans = query(2);
        farNode = 2;
        low = 2;
        high = n;

        while(low <= high)
        {
            mid = (low + high)/2;

            dis = query(mid);

            if(dis >= ans)
            {
                ans = dis;
                farNode = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        cout << "1 " << n-1 << " " << farNode << " ";
        for(i = 1; i <= n; i++)
        {
            if(i != farNode)
                cout << i << " ";
        }
        cout << "\n";
        cin >> ans;
        cout << "-1 " << ans << "\n";
    }
}
