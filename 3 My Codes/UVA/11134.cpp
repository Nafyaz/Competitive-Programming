#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

pair<pair<int, int>, pair<int, int>> rec[5009];
bool rows[5009], cols[5009];
vector<pair<int, int>> v;
int n;

bool func(int r)
{
//    cout << r << "\n";
    if(r > n)
        return 1;

    int i, j;

//    cout << rec[r].ff.ff << " " << rec[r].ss.ff << "\n";
//    cout << rec[r].ff.ss << " " << rec[r].ss.ss << "\n";

    for(i = rec[r].ff.ff; i <= rec[r].ss.ff; i++)
    {
        for(j = rec[r].ff.ss; j <= rec[r].ss.ss; j++)
        {
//            cout << i << "  " << j << "; " << rows[i] << " " << cols[j] << "\n";
            if(rows[i] || cols[j])
                continue;

            rows[i] = 1;
            cols[j] = 1;
            v.push_back({i, j});
            if(func(r+1))
                return 1;
            rows[i] = 0;
            cols[j] = 0;
            v.pop_back();
        }
    }

    return 0;
}

int main()
{
    freopen("out.txt", "w", stdout);

    int i;

    while(1)
    {
        v.clear();

        cin >> n;

        if(!n)
            break;

        for(i = 1; i <= n; i++)
        {
            rows[i] = 0;
            cols[i] = 0;

            cin >> rec[i].ff.ff >> rec[i].ff.ss;
            cin >> rec[i].ss.ff >> rec[i].ss.ss;
        }

        if(!func(1))
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        for(auto u : v)
            cout << u.ff << " " << u.ss << "\n";
    }
}

/*
2
1 1 2 2
1 1 2 2
8
1 1 2 2
5 7 8 8
2 2 5 5
2 2 5 5
6 3 8 6
6 3 8 5
6 3 8 8
3 6 7 8
*/
