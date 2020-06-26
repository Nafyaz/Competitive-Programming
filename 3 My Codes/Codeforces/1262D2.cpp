#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ff first
#define ss second

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.ff == b.ff)
        return a.ss < b.ss;
    return a.ff > b.ff;
}

int main()
{
    int n, m, i, j, k, pos;
    cin >> n;
    int value[n];
    vector <pair <int, int> > v(n);

    for(i = 0; i < n; i++)
    {
        cin >> value[i];

        v[i].ff = value[i];
        v[i].ss = i;
    }

    sort(v.begin(), v.end(), cmp);

//    for(auto u : v)
//        cout << u.ff << " " << u.ss << endl;

    cin >> m;
    vector<pair<pair<int, int>, int> > query(m);
    int ans[m];

    for(i = 0; i < m; i++)
    {
        cin >> k >> pos;
        query[i].ff.ff = k;
        query[i].ff.ss = pos;
        query[i].ss = i;
    }

    sort(query.begin(), query.end());

//    for(auto u : query)
//        cout << u.ff.ff << " " << u.ff.ss << " " << u.ss << endl;

    ordered_set os;
    j = 0;
    for(i = 0; i < m; i++)
    {
        while(os.size() < query[i].ff.ff)
        {
            os.insert(v[j].ss);
            j++;
        }
        pos = *os.find_by_order(query[i].ff.ss - 1);
//        cout << i << " " << pos << endl;
        ans[query[i].ss] = value[pos];
    }

    for(auto u : ans)
        cout << u << endl;
}
