#include<bits/stdc++.h>
using namespace std;

int flag[10000];
vector<int>primes;
vector<int> adj[10000];

void sieve()
{
    int i, j, val = sqrt(10000);
    for(i = 4; i < 10000; i += 2)
        flag[i] = 1;

    for(i = 3; i < val; i++)
    {
        if(!flag[i])
        {
            for(j = i*i; j < 10000; j += 2*i)
                flag[j] = 1;
        }
    }
    for(i = 1000; i < 10000; i++)
    {
        if(!flag[i])
            primes.push_back(i);
    }
}

void make_edges()
{
    int x, j;
    for(auto i : primes)
    {
       for(j = 0; j <= 9; j++)
       {
            x = i/10*10+j;
            if(!flag[x] && x != i)
                adj[i].push_back(x);
           x = i/100*100+10*j + i%10;
           if(!flag[x] && x != i)
                adj[i].push_back(x);
           x = i/1000*1000+100*j + i%100;
           if(!flag[x] && x != i)
                adj[i].push_back(x);
           if(j)
           {
               x = 1000*j + i%1000;
               if(!flag[x] && x != i)
                adj[i].push_back(x);
           }
       }
    }
}

int dis[10000];

void bfs(int s)
{
    int i, x;
    for(i = 0; i < 10000; i++)
        dis[i] = INT_MAX;

    queue<int> q;
    dis[s] = 0;
    q.push(s);

    while(!q.empty())
    {
        x = q.front();
        q.pop();
        for(auto u : adj[x])
        {
            if(dis[u] > dis[x] + 1)
            {
                dis[u] = dis[x] + 1;
                q.push(u);
            }
        }
    }
}


int main()
{
    sieve();
    make_edges();

    int T, s, t, caseno = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &s, &t);
        bfs(s);

        dis[t] == INT_MAX? printf("Impossible\n") : printf("%d\n", dis[t]);
    }
}

