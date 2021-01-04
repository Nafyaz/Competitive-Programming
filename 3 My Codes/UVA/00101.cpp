#include<bits/stdc++.h>
using namespace std;

vector<int> v[25];
int cur[25];

void moveonto(int a, int b)
{
    int i, posa = cur[a], posb = cur[b];

    if(posa == posb)
        return;

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

    if(posa == posb)
        return;

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
    int i, posa = cur[a], posb = cur[b], bidx, aidx;

    if(posa == posb)
        return;

    for(i = 0; i < (int)v[posb].size(); i++)
    {
        if(v[posb][i] == b)
            bidx = i;
    }
    for(i = 0; i < (int)v[posa].size(); i++)
    {
        if(v[posa][i] == a)
            aidx = i;
    }

    stack<int> st;
    for(i = (int)v[posa].size() - 1; i >= aidx; i--)
    {
        st.push(v[posa][i]);
        cur[v[posa][i]] = posb;
        v[posa].pop_back();
    }

    while(!st.empty())
    {
        v[posb].insert(v[posb].begin() + bidx, st.top());
        st.pop();
    }
}

void pileover(int a, int b)
{
    int i, posa = cur[a], posb = cur[b], aidx;

    if(posa == posb)
        return;

    for(i = 0; i < (int)v[posa].size(); i++)
    {
        if(v[posa][i] == a)
            aidx = i;
    }

    stack<int> st;
    for(i = (int)v[posa].size() - 1; i >= aidx ; i--)
    {
        st.push(v[posa][i]);
        cur[v[posa][i]] = posb;
        v[posa].pop_back();
    }

    while(!st.empty())
    {
        v[posb].push_back(st.top());
        st.pop();
    }
}


int main()
{
//    freopen("out.txt", "w", stdout);
    int n, i, a, b;
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

    for(i = 0; i < n; i++)
    {
        cout << i << ": ";

        for(auto u : v[i])
            cout << u << " ";
        cout << "\n";
    }
}
