#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int c, n, t, m, i, time, arr_t, bank, ferry;
    string s;

    queue<pair<int, int>> cars[2];
    int ans[10009];

    cin >> c;

    while(c--)
    {
        cin >> n >> t >> m;

        while(!cars[0].empty())
            cars[0].pop();
        while(!cars[1].empty())
            cars[1].pop();

        for(i = 0; i < m; i++)
        {
            cin >> arr_t >> s;

            if(s == "left")
                cars[0].push({arr_t, i});
            else
                cars[1].push({arr_t, i});
        }

        time = 0;
        bank = 0;
        ferry = 0;

        while(!cars[0].empty() || !cars[1].empty())
        {
            int mn = INT_MAX;
            if(!cars[0].empty())
                mn = min(mn, cars[0].front().ff);
            if(!cars[1].empty())
                mn = min(mn, cars[1].front().ff);

            time = max(time, mn);

            while(!cars[bank].empty() && ferry < n && cars[bank].front().ff <= time)
            {
                ans[cars[bank].front().ss] = time + t;
                cars[bank].pop();
                ferry++;
            }

            time = time + t;
            bank = bank ^ 1;
            ferry = 0;
        }

        for(i = 0; i < m; i++)
            cout << ans[i] << "\n";

        if(c)
            cout << "\n";
    }
}
