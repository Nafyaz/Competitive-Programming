#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c, d, n, m, k;

    cin >> c >> d >> n >> m >> k;

    int need = max(0, n*m-k), ans = INT_MAX;

    for(int i = 0; i <= (need+n-1)/n; i++)
        ans = min(ans, c*i + max(0, (need-n*i))*d);

    cout << ans;
}
