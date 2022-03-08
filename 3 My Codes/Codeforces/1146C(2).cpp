#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, n, i, bit, ans, dis;

    cin >> t;

    while(t--)
    {
        cin >> n;

        ans = 0;
        for(bit = 1; bit <= n; bit *= 2)
        {
            queue<ll> q1, q2;

            for(i = 1; i <= n; i++)
                (i&bit? q1 : q2).push(i);

            cout << q1.size() << " " << q2.size() << " ";
            while(!q1.empty())
            {
                cout << q1.front() << " ";
                q1.pop();
            }
            while(!q2.empty())
            {
                cout << q2.front() << " ";
                q2.pop();
            }
            cout << "\n";

            cin >> dis;

            ans = max(ans, dis);
        }

        cout << "-1 " << ans << "\n";
    }
}
