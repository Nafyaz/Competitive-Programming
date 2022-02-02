#include<bits/stdc++.h>
using namespace std;

int l[100005], r[100005];
double prob[100005];

int main()
{
    int n, p, i;
    double ans = 0;

    cin >> n >> p;

    for(i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        prob[i] = (double)(r[i]/p - (l[i]-1)/p) / (r[i] - l[i] + 1);
    }

    for(i = 0; i < n; i++)
        ans += 2000*(1 - (1 - prob[i])*(1 - prob[(i+1)%n]));

    cout << fixed << setprecision(6) << ans;
}
