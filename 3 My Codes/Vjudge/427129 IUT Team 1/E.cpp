#include<bits/stdc++.h>
using namespace std;

int r, c, dir, cr, cc, cdir;
string grid[509];
vector<pair<int, int>> cells;

int main()
{
    int t, i, j, q, sr, sc, x;
    char sdir, ins;

    cin >> t;

    while(t--)
    {
        cin >> r >> c >> q;
        cin >> sr >> sc >> sdir;

        cr = sr-1;
        cc = sc-1;

        switch(sdir)
        {
        case 'U':
            dir = 0;
            break;
        case 'R':
            dir = 1;
            break;
        case 'D':
            dir = 2;
            break;
        case 'L':
            dir = 3;
            break;
        }

        cdir = dir;

        for(i = 0; i < r; i++)
            cin >> grid[i];

        cells.clear();
        cells.push_back({cr, cc});
        while(q--)
        {
            cin >> ins;
            if(ins == 'R')
                cdir = (cdir+1)%4;
            else
            {
                cin >> x;
                while(x--)
                {
                    while(next)
                    cells.push_back({cr, cc});
                }
            }
        }
    }
}
