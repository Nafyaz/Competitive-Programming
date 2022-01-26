#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll pre[100005];

int main()
{
    ll n, k, i, a, ans = 0;

    cin >> n >> k;

    for(i = 1; i <= n; i++)
    {
        cin >> a;
        pre[i] = pre[i-1] + a;

        ans += upper_bound(pre, pre+i, pre[i]-k) - pre;
//        cout << "i: " << i << "; ans: " << ans << "\n";
    }
    cout << ans;
}
