#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, w, k, i, x, y[109], caseno = 0;
    cin >> t;
    while(t--)
    {
        cin >> n >> w >> k;
        for(i = 0; i < n; i++)
            cin >> x >> y[i];
        sort(y, y+n);

        int ans = 1, up = y[0] + w;
        for(i = 0; i < n; i++)
        {
            if(up > y[i])
            {
                ans++;
                up = y[i] + w;
            }
        }

        cout << "Case " << ++caseno << ": " << ans << endl;
    }
}
