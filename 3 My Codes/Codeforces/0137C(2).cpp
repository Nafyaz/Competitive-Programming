#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back

int main()
{
    int n, i, j, x, y;
    vector<pair<int, int> > v;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.pb({x, y});
    }

    sort(v.begin(), v.end());

    int mx[100009];
    for(i = 0; i < n; i++)
    {
        if(i)
            mx[i] = max(mx[i-1], v[i].ss);
        else
            mx[i] = v[i].ss;
    }

    int ans = 0;
    for(i = n-1; i > 0; i--)
    {
        if(mx[i-1] > v[i].ss)
            ans++;
    }

    cout << ans;
}
