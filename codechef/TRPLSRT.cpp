#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back

int main()
{
    int t, n, k, p[200009], i;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i = 1; i <= n; i++)
            cin >> p[i];

        vector<pair<int, pair<int, int> > > v;
        for(i = 1; i <= n; i++)
        {
//            cout << i << " " << p[i] << " " << p[p[i]] << endl;
            while(p[i] != i && p[p[i]] != i)
            {
                int a = p[i], b = p[p[i]], c = p[p[p[i]]];
                p[i] = c, p[a] = a, p[b] = b;
                v.pb({i, {a, b}});
            }
        }

//        for(auto u : v)
//            cout << u.ff << " " << u.ss.ff << " " << u.ss.ss << endl;
//        for(i = 1; i <= n; i++)
//            cout << p[i] << " ";

        int a = -1, b, c, d;
        for(i = 1; i <= n; i++)
        {
            if(p[i] != i && p[p[i]] == i)
            {
                if(a == -1 || p[i] == a)
                {
                    a = i, b = p[i];
                    continue;
                }

                c = i, d = p[i];
                p[a] = d, p[b] = b, p[c] = a;
                v.pb({a, {b, c}});

                p[a] = a, p[c] = c, p[d] = d;
                v.pb({a, {d, c}});

                a = -1;
            }
        }

//        cout << a;
        if(v.size() > k || a != -1)
        {
            cout << -1 << endl;
            continue;
        }

        cout << v.size() << endl;
        for(auto u : v)
            cout << u.ff << " " << u.ss.ff << " " << u.ss.ss << endl;
//        for(i = 1; i <= n; i++)
//            cout << p[i] << " ";
    }
}
