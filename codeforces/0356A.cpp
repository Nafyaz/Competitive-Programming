#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

int main()
{
    int n, m, i, l, r, x, lpos, rpos, ival;
    queue <int> q;
    ordered_set<int> s;
    cin >> n >> m;

    int d[n+1] = {0};
    for(i = 1; i <= n; i++)
        s.insert(i);

    while(m--)
    {
        cin >> l >> r >> x;
        lpos = s.order_of_key(l);
        rpos = s.order_of_key(r);

        for(i = lpos; i <= rpos; i++)
        {
            ival = *(s.find_by_order(i));
            if(ival >= l && ival <= r)
                q.push(ival);
            d[ival] = x;
//            cout << i << " " << ival << endl;
        }
        while(!q.empty())
        {
            s.erase(q.front());
            q.pop();
        }
        s.insert(x);
        d[x] = 0;
    }

    for(i = 1; i <= n; i++)
        cout << d[i] << " ";
}
