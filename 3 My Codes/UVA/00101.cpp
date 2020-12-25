#include<bits/stdc++.h>
using namespace std;

vector<int> v[25];
int cur[25];

void moveonto(int a, int b)
{
    int i, posa = cur[a], posb = cur[b];

    for(i = 0; i < (int)v[posa].size(); i++)
    {
        if(v[posa][i] == a)
        {
            v[posa].erase(v[posa].begin() + i);
            break;
        }
    }

    for(i = 0; i < (int)v[posb].size(); i++)
    {
        if(v[posb][i] == b)
        {
            v[posb].insert(v[posb].begin() + i + 1, a);
            break;
        }
    }

    cur[a] = posb;
}

void moveover(int a, int b)
{
    int i, posa = cur[a], posb = cur[b];

    for(i = 0; i < (int)v[posa].size(); i++)
    {
        if(v[posa][i] == a)
        {
            v[posa].erase(v[posa].begin() + i);
            break;
        }
    }

    v[posb].push_back(a);

    cur[a] = posb;
}

void pileonto(int a, int b)
{
    int i, posa = cur[a], posb = cur[b], bi;

    for(i = 0; i < (int)v[posb].size(); i++)
    {
        if(v[posb][i] == b)
            bi = i;
    }

    for(i = 0; i < (int)v[posa].size(); i++)
    {
        v[posb].insert(v[posb].begin() + bi, v[posa][i]);
        cur[v[posa][i]] = posb;
    }

    v[posb].clear();

}

void pileover(int a, int b)
{
    int i, posa = cur[a], posb = cur[b];

    for(i = 0; i < (int)v[posa].size(); i++)
    {
        v[posb].push_back(v[posa][i]);
        cur[v[posa][i]] = posb;
    }

    v[posa].clear();
}


int main()
{
    int n, i, j, a, b;
    string x1, x2;

    cin >> n;
    for(i = 0; i < n; i++)
    {
        v[i].push_back(i);
        cur[i] = i;
    }

    while(1)
    {
        cin >> x1;
        if(x1 == "quit")
            break;

        cin >> a >> x2 >> b;

        if(x1 == "move" && x2 == "onto")
            moveonto(a, b);
        else if(x1 == "move" && x2 == "over")
            moveover(a, b);
        else if(x1 == "pile" && x2 == "onto")
            pileonto(a, b);
        else
            pileover(a, b);

        for(i = 0; i < n; i++)
        {
            cout << i << ", " << cur[i] << ": ";

            for(auto u : v[i])
                cout << u << " ";
            cout << "\n";
        }
    }
}
