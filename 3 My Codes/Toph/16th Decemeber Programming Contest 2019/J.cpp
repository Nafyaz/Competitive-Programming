#include<bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template<typename T>
//using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

int n, a[40009], tree[40009], l, r;
void build(int s, int e, int node)
{
    if(s == e)
    {
        tree[node] = a[s];
        return;
    }

    int mid = (s+e)/2, left = 2*node+1, right = 2*node+2;

    build(s, mid, left);
    build(mid+1, e, right);

    tree[node] = max(tree[left], tree[right]);
}

int query(int s, int e, int node)
{
    if(s > r || e < l)
        return INT_MIN;
    if(s >= l && e <= r)
        return tree[node];

    int left = 2*node + 1;
    int right = 2*node + 2;
    int mid = (s+e)/2;

    int p1 = query(s, mid, left);
    int p2 = query(mid+1, e, right);

    return max(p1, p2);
}
int main()
{
    int t, i, j, q, caseno = 0, mx;
    vector<int> v[10009];
    map<int, int> mp;
    cin >> t;
    while(t--)
    {
        j = 0;
        mp.clear();
        for(i = 0; i < 10009; i++)
            v[i].clear();

        cin >> n >> q;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            if(mp.find(a[i]) == mp.end())
            {
                mp[a[i]] = j;
                j++;
            }
            v[mp[a[i]]].push_back(i);
        }
        build(0, n-1, 0);

        cout << "Case " << ++caseno << ":" << endl;
        for(i = 0; i < q; i++)
        {
            cin >> l >> r;
            mx = query(0, n-1, 0);
            mx = mp[mx];
            cout << upper_bound(v[mx].begin(), v[mx].end(), r) - lower_bound(v[mx].begin() , v[mx].end(), l) << endl;
        }
    }
}
