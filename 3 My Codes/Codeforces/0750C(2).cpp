#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll c[200005], d[200005];
ll preSum[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, d2Cnt = 0, d1Min, d2Max;

    cin >> n;

    d1Min = INT_MAX;
    d2Max = INT_MIN;
    for(i = 1; i <= n; i++)
    {
        cin >> c[i] >> d[i];
        preSum[i] = preSum[i-1] + c[i];

        if(d[i] == 1)
            d1Min = min(d1Min, preSum[i-1]);
        else
            d2Max = max(d2Max, preSum[i-1]);

        d2Cnt += (d[i] == 2);
    }

    if(d2Cnt == 0)
    {
        cout << "Infinity";
        return 0;
    }

    if(d1Min <= d2Max)
    {
        cout << "Impossible";
        return 0;
    }

    cout << 1899 - d2Max + preSum[n];
}
