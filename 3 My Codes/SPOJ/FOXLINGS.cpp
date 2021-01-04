#include<bits/stdc++.h>
using namespace std;

map<int, int> parent;

int Find(int x)
{
    if(parent.find(x) == parent.end())
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x), y = Find(y);
    if(x != y)
        parent[x] = y;
}

int main()
{
    int n, m, ans, a, b;


    cin >> n >> m;

    while(m--)
    {
        cin >> a >> b;
        Union(a, b);
    }

    cout << n - parent.size();
}
