#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int t, n, m, i, x, mx, freq[10];

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        queue<pair<int, int>> q;
        memset(freq, 0, sizeof freq);
        freq[0] = -1;
        mx = 0;

        for(i = 0; i < n; i++)
        {
            cin >> x;
            q.push({i, x});
            freq[x]++;
            mx = max(mx, x);
        }

        while(!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();

            if(p.ss < mx)
            {
                q.push(p);
            }
            else if(p.ff == m)
            {
                break;
            }
            else
            {
                freq[p.ss]--;
                while(freq[mx] == 0)
                    mx--;
            }
        }

        cout << n - q.size() << "\n";
    }
}
