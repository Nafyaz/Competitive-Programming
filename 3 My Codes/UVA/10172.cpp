#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, n, s, q, i, j;
    int qi, dest, total, curr_stat, box, ans;

    cin >> T;

    while(T--)
    {
        cin >> n >> s >> q;

        stack<int> carrier;
        queue<int> stations[n+1];

        total = 0;

        for(i = 1; i <= n; i++)
        {
            cin >> qi;

            total += qi;

            while(qi--)
            {
                cin >> dest;
                stations[i].push(dest);
            }
        }

        curr_stat = 1;
        ans = 0;
        while(1)
        {
            while(!carrier.empty())
            {
                box = carrier.top();
                if(box == curr_stat)
                {
                    total--;
                    carrier.pop();
                    ans++;
                }
                else if(stations[curr_stat].size() < q)
                {
                    stations[curr_stat].push(box);
                    carrier.pop();
                    ans++;
                }
                else
                    break;
            }

            while(!stations[curr_stat].empty())
            {
                box = stations[curr_stat].front();
                if(carrier.size() < s)
                {
                    carrier.push(box);
                    stations[curr_stat].pop();
                    ans++;
                }
                else
                    break;
            }

            if(!total)
                break;
            else
            {
                curr_stat++;
                if(curr_stat > n)
                    curr_stat = 1;
                ans += 2;
            }
        }

        cout << ans << "\n";
    }
}
