#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

//bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
//{
//    if(a.ff.ss != b.ff.ss)
//        return a.ff.ss < b.ff.ss;
//    return a.ff.ff > b.ff.ff;
//}

int main()
{
    int t, caseno = 0, n, i, j, a, b, x;
    int ans[1009];
    vector<pair<pair<int, int>, int> > v;
    cin >> t;
    while(t--)
    {
        v.clear();

        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> a >> b;
            v.push_back({{a, b}, i});
            ans[i] = 0;
        }

        sort(v.begin(), v.end());

        x = 0;
        for(i = 0; i < n; i++)
        {
            if(!ans[v[i].ss] && x <= v[i].ff.ff)
            {
                x = v[i].ff.ss;
                ans[v[i].ss] = 1;
            }
        }
        x = 0;
        for(i = 0; i < n; i++)
        {
            if(!ans[v[i].ss] && x <= v[i].ff.ff)
            {
                x = v[i].ff.ss;
                ans[v[i].ss] = 2;
            }
        }

        bool flag = 1;
        for(i = 0; i < n; i++)
        {
            if(!ans[i])
                flag = 0;
        }

        cout << "Case #" << ++caseno << ": ";
        if(!flag)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        for(i = 0; i < n; i++)
        {
            if(ans[i] == 1)
                cout << 'C';
            else
                cout << 'J';
        }
        cout << endl;
    }
}
