#include<bits/stdc++.h>
using namespace std;

int a[100005];
bool vis[100005];

int main()
{
    int n, x, i, ans = 0;

    cin >> n >> x;

    for(i = 1; i <= n; i++)
        cin >> a[i];

    for(; !vis[x]; x = a[x])
    {
        vis[x] = 1;
        ans++;
    }

    cout << ans;
}
