#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, a, b, step, diff, sum, ans;

    cin >> t;

    while(t--)
    {
        cin >> a >> b;

        diff = abs(a - b);
        ans = sum = 0;

        for(step = 1; sum < diff || (sum - diff)%2 == 1; step++, ans++)
            sum += step;

        cout << ans << "\n";
    }
}
