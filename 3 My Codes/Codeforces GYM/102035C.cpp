#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll p[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, x, i, boxCnt;
    __int128 low, high, mid, cost;

    cin >> n >> k >> x;

    for(i = 1; i <= n; i++)
        cin >> p[i];

    low = 0;
    high = 2e18;

    while(low <= high)
    {
        mid = low + (high - low)/2;

        for(i = 1, boxCnt = 0; i <= n; i++)
        {
            if(mid >= p[i])
                boxCnt += (mid - p[i])/x + 1;
        }

        if(boxCnt >= k)
        {
            cost = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    for(i = 1; i <= n; i++)
    {
        if(cost >= p[i])
        {
            boxCnt = min(k, (ll)(cost - p[i])/x + 1);
            k -= boxCnt;

            cout << boxCnt << " ";
        }
        else
            cout << "0 ";
    }
}

