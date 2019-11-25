#include<bits/stdc++.h>
using namespace std;

int parent[110];

int find(int x)
{
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void merge(int x, int y)
{
    int px = find(x);
    int py = find(y);
    parent[px] = py;
}

int main()
{

    int n, m, i, j, lan, u;
    scanf("%d %d", &n, &m);

    for(i = 0; i < n; i++)
        parent[i] = i;

    vector <int> v[n+1];
    int zero = 0;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &lan);
        if(lan == 0)
        {
            zero++;
        }
        for(j = 0; j < lan; j++)
        {
            scanf("%d", &u);
            v[i].push_back(u);
        }
    }
    for(i = 0; i < n; i++)
    {
        for(auto x : v[i])
        {
            for(j = i+1; j < n; j++)
            {
                for(auto y : v[j])
                {
                    if(x == y)
                    {
                        merge(i, j);
                        break;
                    }
                }
            }
        }
    }

//    for(i = 0; i < n; i++)
//        printf("%d: %d ", i, parent[i]);
//    printf("\n");

    int connected = 0;
    for(i = 0; i < n; i++)
    {
        if(parent[i] == i)
            connected++;
    }
    zero == connected? printf("%d", zero) : printf("%d", connected - 1);
}
