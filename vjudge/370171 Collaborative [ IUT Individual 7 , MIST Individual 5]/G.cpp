#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    freopen("out.txt", "w", stdout);
    int n, t, m, i, x, a[100009], b[100009];
    map<int, int> mp;
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> t >> m;
        mp.clear();
        for(i = 0; i < m; i++)
        {
            cin >> x;
            mp[x]++;
        }

        i = 0;
        for(auto u : mp)
        {
            a[i] = u.ff;
            b[i] = u.ss;
            i++;
        }
        a[i] = INT_MAX;
        b[i] = 0;

        int sz = mp.size(), tr = 0, tm = 0;
        for(i = 0; i < sz; i++)
        {
            x = a[i] + (b[i] + n - 1)/n*2*t;
            if(x <= a[i+1])
            {
                tr += (b[i] + n - 1)/n;
                tm = max(tm, x);
            }
            else
            {
                x = a[i] + 2*t*(b[i]/n);
                tr += b[i]/n;
                tm = max(tm, x);
                b[i+1] += b[i] - b[i]/n*n;
            }

            a[i+1] = max(a[i+1], x);
        }

        cout << tm - t << " " << tr << endl;
    }
}
/*
2
2 10 10
0
10
20
30
40
50
60
70
80
90
2 10 3
10
30
40
*/
