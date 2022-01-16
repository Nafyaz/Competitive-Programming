#include<bits/stdc++.h>
using namespace std;

int degree[400005];
vector<int> adj[400005];
int distFromEnd[400005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, d, k, i, mx, node;

    cin >> n >> d >> k;

    if(d+1 > n)
    {
        cout << "NO";
        return 0;
    }

    mx = 0;
    for(i = 1; i <= d; i++)
    {
        degree[i]++;
        degree[i+1]++;

        adj[i].push_back(i+1);

        mx = max({mx, degree[i], degree[i+1]});

        distFromEnd[i] = min(i-1, d-i+1);
    }

    if(mx > k)
    {
        cout << "NO";
        return 0;
    }

    for(i = 1, node = d+2; i <= n; i++)
    {
        if(distFromEnd[i] > 0)
        {
            while(degree[i] < k && node <= n)
            {
                adj[i].push_back(node);
                degree[i]++;
                degree[node]++;
                distFromEnd[node] = distFromEnd[i] - 1;
                node++;
            }
        }
    }

//    for(i = 1; i <= n; i++)
//    {
//        cout << i << " " << distFromEnd[i] << "; ";
//        for(auto u : adj[i])
//            cout << u << " ";
//        cout << "\n";
//    }

    if(degree[n] == 0)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    for(i = 1; i <= n; i++)
    {
        for(auto u : adj[i])
            cout << i << " " << u << "\n";
    }
}
