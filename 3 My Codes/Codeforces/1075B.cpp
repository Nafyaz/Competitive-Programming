#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, n, m;
    cin >> n >> m;
    int x[n+m], t[n+m], driver[m];

    for(i = 0; i < n+m; i++)
        cin >> x[i];

    j = 0;
    for(i = 0; i < n+m; i++)
    {
        cin >> t[i];

        if(t[i])
        {
            driver[j] = x[i];
            j++;
        }
    }

    sort(driver, driver + m);
    int pos, ans[m] = {0};

    for(i = 0; i < n+m; i++)
    {
        if(t[i])
            continue;
        pos = lower_bound(driver, driver+m, x[i]) - driver;
        if(pos == 0)
            ans[0]++;
        else if(pos == m)
            ans[m-1]++;
        else
        {
            if(x[i] - driver[pos-1] <= driver[pos] - x[i])
                ans[pos - 1]++;
            else
                ans[pos]++;
        }
    }

    for(auto u : ans)
        cout << u << " ";
}
