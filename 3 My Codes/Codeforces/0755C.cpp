#include<bits/stdc++.h>
using namespace std;

int n;
int parent[10004];

int Find(int x)
{
    if(parent[x] == x)
        return x;

    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    parent[max(x, y)] = min(x, y);
}

int main()
{
    int i, p, cnt = 0;
    cin >> n;

    for(i = 1; i <= n; i++)
        parent[i] = i;

    for(i = 1; i <= n; i++)
    {
        cin >> p;

        Union(i, p);
    }

    for(i = 1; i <= n; i++)
        cnt += (parent[i] == i);

    cout << cnt;
}
