#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, i, d[200005], l, r, sum1, sum2, ans;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> d[i];

    ans = sum1 = sum2 = 0;
    l = -1, r = n;

    while(l+1 < r)
    {
        if(sum1 > sum2)
        {
            r--;
            sum2 += d[r];
        }
        else
        {
            l++;
            sum1 += d[l];
        }

        ans = max(ans, (sum1 == sum2)*sum1);
    }

    cout << ans;
}
