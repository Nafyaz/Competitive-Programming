#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int t, n, m, c[409], last[409], i;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        memset(last, -1, sizeof last);
        for(i = 0; i < m; i++)
        {
            cin >> c[i];
            last[c[i]] = i;
        }

        mul<pair<int, int> > pq;

        while(pq.size() < n)
            pq.push({INT_MAX, 0});

        int ans = 0, present[409] = {0};
        for(i = 0; i < m; i++)
        {
            if(!present[c[i]])
            {
                present[pq.top().ss] = 0;
                pq.pop();
                ans++;
                pq.push({last[c[i]], c[i]});
                present[c[i]] = 1;
            }

        }

        cout << ans << endl;
    }
}
