// Follow Bojack
#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int main()
{
    int n, m, d, i, j;
    pair<int, int> a[200005];
    int ans[200005], mx;

    cin >> n >> m >> d;

    for(i = 0; i < n; i++)
    {
        cin >> a[i].ff;
        a[i].ss = i;
    }

    sort(a, a+n);

    mx = j = 0;
    for(i = 0; i < n; i++)
    {
        while(j < n && a[j].ff - a[i].ff <= d)
            j++;

        mx = max(mx, j-i);
    }

    for(i = 0; i < n; i++)
        ans[a[i].ss] = i%mx + 1;

    cout << mx << "\n";
    for(i = 0; i < n; i++)
        cout << ans[i] << " ";
}
