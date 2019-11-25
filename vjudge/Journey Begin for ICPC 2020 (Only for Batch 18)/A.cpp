#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int i, n, m, x;
    cin >> n >> m;
    pair<int, pair<int, int>> pos[n+1];
    int val[n+1], y;

    for(i = 1; i <= n; i++)
    {
        pos[i].ff = pos[i].ss.ff = pos[i].ss.ss = i;
        val[i] = i;
    }

    for(i = 0; i < m; i++)
    {
        cin >> x;
        y = pos[x].ff;
        if(y != 1)
        {
            swap(val[y], val[y-1]);
            pos[x].ff--;
            pos[x].ss.ff = min(pos[x].ss.ff, pos[x].ff);

            x = val[y];
            pos[x].ff++;
            pos[x].ss.ss = max(pos[x].ss.ss, pos[x].ff);
        }

////        cout << val[1] << " " << val[2] << " " << val[3] << endl;
//        cout << pos[1].ff << " " << pos[2].ff << " " << pos[3].ff << endl;
//        cout << pos[x].ss.ss << endl;

    }
    for(i = 1; i <= n; i++)
        cout << pos[i].ss.ff << " " << pos[i].ss.ss << endl;
}
