#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ff first
#define ss second

int main()
{
    int n, i, j, p1, p2;
    while(1)
    {
        cin >> n;
        if(!n)
            break;

        vector<pair<ld, ld>> v;

        for(i = 0; i < n; i++)
        {
            cin >> p1 >> p2;
            v.push_back({p1, p2});
        }

        set<ld> s;
        for(i = 0; i < n; i++)
        {
            for(j = i+1; j < n; j++)
            {
                if((v[j].ff - v[i].ff) == 0)
                    s.insert(INT_MAX);
                else
                    s.insert((v[j].ss - v[i].ss) / (v[j].ff - v[i].ff));

//                cout << (v[j].ss - v[i].ss) / (v[j].ff - v[i].ff) << endl;
            }
        }

//        for(auto u : s)
//            cout << u << endl;
        cout << s.size() << endl;
    }
}
