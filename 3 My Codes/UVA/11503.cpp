#include<bits/stdc++.h>
using namespace std;

int p[200009], sz[200009];
string s[200009];
map<string, int> mp;

int Find(int u)
{
    if(p[u] == u)
        return u;

    return p[u] = Find(p[u]);
}

void Union(int u, int v)
{
    u = Find(u);
    v = Find(v);

    if(u == v)
        return;

    p[max(u, v)] = min(u, v);
    sz[min(u, v)] += sz[max(u, v)];
//    cout << p[u] << " " << p[v] << "\n";
//    cout << sz[u] << " " << sz[v];
}

int main()
{
    int t, f, u, v, idx, i;
    string su, sv;

    cin >> t;

    while(t--)
    {
        cin >> f;
        mp.clear();
        idx = 0;

        while(f--)
        {
            cin >> su >> sv;

            if(mp.find(su) == mp.end())
            {
                mp[su] = idx;
                s[idx] = su;

                p[idx] = idx;
                sz[idx] = 1;

                idx++;
            }
            u = mp[su];

            if(mp.find(sv) == mp.end())
            {
                mp[sv] = idx;
                s[idx] = sv;

                p[idx] = idx;
                sz[idx] = 1;

                idx++;
            }
            v = mp[sv];

            Union(u, v);

//            cout << u << " " << v << "\n";
//            for(i = 0; i < idx; i++)
//                cout << Find(i) << " ";
//            cout << "\n";
//            for(i = 0; i < idx; i++)
//                cout << sz[i] << " ";
//            cout << "\n";


            cout << sz[Find(u)] << "\n";
        }


    }
}
