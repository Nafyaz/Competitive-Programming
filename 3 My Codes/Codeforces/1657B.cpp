#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, B, x, y, i, a, ans;

    cin >> T;

    while(T--)
    {
        cin >> n >> B >> x >> y;

        ans = a = 0;
        for(i = 1; i <= n; i++)
        {
            if(a + x <= B)
            {
                a += x;
                ans += a;
            }
            else
            {
                a -= y;
                ans += a;
            }
        }

        cout << ans << "\n";
    }
}
