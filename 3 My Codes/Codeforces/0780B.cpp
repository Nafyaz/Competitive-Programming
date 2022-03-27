#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
double x[60004], v[60004];

double getDist(double p)
{
    ll i;
    double ret = 0;
    for(i = 0; i < n; i++)
        ret = max(ret, abs(x[i]-p)/v[i]);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i;
    double low = INT_MAX, high = 0, mid1, mid2;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> x[i];
        low = min(low, x[i]);
        high = max(high, x[i]);
    }

    for(i = 0; i < n; i++)
        cin >> v[i];

    for(i = 0; i < 100; i++)
    {
        mid1 = (2*low + high)/3;
        mid2 = (low + 2*high)/3;

        if(getDist(mid1) < getDist(mid2))
            high = mid2;
        else
            low = mid1;
    }

    cout << fixed << setprecision(7) << getDist((low+high)/2);
}
