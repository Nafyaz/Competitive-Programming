#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> mx(n);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        mx[y - 1] = max(mx[y - 1], x);
    }
    for (int i = n - 2; i >= 0; --i)
        mx[i] = max(mx[i], mx[i + 1]);
    int ans = 0;
    for (int i = 0; i < n; )
    {
        int j = i, x = 0;
        while (j < n && mx[j - i] >= max(x, a[j]))
        {
            x = max(x, a[j]);
            ++j;
        }
        if (j == i)
        {
            cout << -1 << "\n";
            return;
        }
        ++ans;
        i = j;
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
