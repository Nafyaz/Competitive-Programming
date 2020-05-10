#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back

int sparse[100009][20], Log[100009];
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

    for(i = 2; i <= n; i++)
        Log[i] = Log[i>>1] + 1;

    for(i = 0; i < n; i++)
        sparse[i][0] = v[i].ss;

    for(j = 1; (1<<(j-1)) < n; j++)
    {
        for(i = 0; i + (1<<(j-1)) < n; i++)
            sparse[i][j] = max(sparse[i][j-1], sparse[i + (1<<(j-1))][j-1]);
    }

    int ans = 0, l, r, h, mx;
    for(i = n-1; i > 0; i--)
    {
        l = 0, r = i-1;
        h = Log[r - l + 1];
        mx = max(sparse[l][h], sparse[r-(1<<h) + 1][h]);
        if(mx > v[i].ss)
            ans++;
    }

    cout << ans;
}
