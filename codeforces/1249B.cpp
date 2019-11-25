#include<bits/stdc++.h>
using namespace std;

int n, parent[200009], p;

int Find(int i)
{
    if(parent[i] == i)
        return i;
    parent[i] = Find(parent[i]);

    return parent[i];
}

void Union(int i, int j)
{
    int x, y;
    x = Find(i);
    y = Find(j);

    parent[x] = y;
}

int main()
{
    int q, i, a[200009];
    cin >> q;
    while(q--)
    {
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            parent[i] = i;
            a[i] = 0;
        }

        for(i = 1; i <= n; i++)
        {
            cin >> p;
            Union(i, p);
        }

        for(i = 1; i <= n; i++)
            a[Find(i)]++;

        for(i = 1; i <= n; i++)
            cout << a[Find(i)] << " ";
        cout << endl;

    }
}
