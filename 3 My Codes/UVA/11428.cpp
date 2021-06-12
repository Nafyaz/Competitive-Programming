#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second

map<int, pii> mp;

int main()
{
    int x, y, N, val;

    /*
    int xmax = -1, ymax = -1, val;

    for(int x = 1; x <= 100; x++)
    {
        for(int y = 1; y <= 100; y++)
        {
            val = x*x*x - y*y*y;
            if(val > 0 && val <= 10000)
            {
                xmax = max(xmax, x);
                ymax = max(ymax, y);
            }
        }
    }

    cout << xmax << " " << ymax;
    */

    for(y = 1; y <= 57; y++)
    {
        for(x = y+1; x <= 58; x++)
        {
            val = x*x*x - y*y*y;
            if(mp.find(val) == mp.end())
                mp[val] = {x, y};
        }
    }

    while(1)
    {
        cin >> N;

        if(!N)
            break;

        if(mp.find(N) == mp.end())
            cout << "No solution\n";
        else
            cout << mp[N].ff << " " << mp[N].ss << "\n";
    }

}
