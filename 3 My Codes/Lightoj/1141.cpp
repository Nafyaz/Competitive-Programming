#include<bits/stdc++.h>
using namespace std;

int t, flag[1010];
vector <int> primes;
vector <int> adj[1010];

void sieve()
{
    int i, j, val = sqrt(1010) + 1;
    for(i = 4; i < 1010; i += 2)
        flag[i] = 1;
    for(i = 3; i < val; i++)
    {
        if(!flag[i])
        {
            for(j = i*i; j < 1010; j += 2*i)
                flag[j] = 1;
        }
    }
    for(i = 2; i < 1010; i++)
    {
        if(!flag[i])
            primes.push_back(i);
    }
}

void make_adj()
{
    int i, j;
    for(i = 4; i < 1010; i++)
    {
        for(j = 0; primes[j] < i; j++)
        {
            if(i % primes[j] == 0)
                adj[i].push_back(primes[j]);
        }
    }
}

int dis[1010];

void bfs(int s)
{
    for(int i = 0; i < 1010; i++)
        dis[i] = INT_MAX;
    dis[s] = 0;

    queue <int> q;
    q.push(s);

    int x;
    while(!q.empty())
    {
        x = q.front();
        q.pop();

        for(auto u : adj[x])
        {
            if(dis[x + u] > dis[x] + 1 && x + u <= t)
            {
                q.push(x + u);
                dis[x + u] = dis[x] + 1;
            }
        }
    }
}

int main()
{
    sieve();
    make_adj();

    int s, T, caseno = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &s, &t);

        bfs(s);

        dis[t] == INT_MAX? printf("Case %d: -1\n", ++caseno) : printf("Case %d: %d\n", ++caseno, dis[t]);
    }
}

