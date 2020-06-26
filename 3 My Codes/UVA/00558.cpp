#include<bits/stdc++.h>
using namespace std;

long long n, m, dis[1009][1009];
vector<pair<long long, long long>> adj[1009];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    long long t, i, j, k, u, v, w, flag;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                dis[i][j] = INT_MAX;
        }

        for(i = 0; i < n; i++)
        {
            adj[i].clear();
            dis[i][j] = 0;
        }

        for(i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            adj[u].push_back({w, v});
            dis[u][v] = w;
        }


        for(k = 0; k < n; k++)
        {
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < n; j++)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }

//        for(i = 0; i < n; i++)
//        {
//            for(j = 0; j < n; j++)
//                cout << setw(10) << dis[i][j] << " ";
//            cout << endl;
//        }

        flag = 0;
        for(i = 0; i < n; i++)
        {
            if(dis[i][i] < 0)
            {
                flag = 1;
                break;
            }
        }

        cout << (flag? "possible" : "not possible") << endl;
    }
}
/*
2
3 3
0 1 1000
1 2 15
2 1 -42
4 4
0 1 10
1 2 20
2 3 30
3 0 -60
*/
