#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, a, b;
    cin >> n >> m;
    int ans = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a >> b;
        if(a + i <= m)
            ans += b;
    }

    cout << ans;
}
