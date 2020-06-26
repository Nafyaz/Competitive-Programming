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
    ll n, i, j, l, x, flag;
    cin >> n;
    vector<ll> s[n], st, ed, mp;

    for(i = 0; i < n; i++)
    {

        cin >> l;
        flag = 0;
        for(j = 0; j < l; j++)
        {
            cin >> x;
            s[i].push_back(x);

            if(j > 0 && x > s[i][j-1])
                flag = 1;
        }

        if(!flag)
        {
            st.push_back(s[i][0]);
            ed.push_back(s[i].back());
            mp.push_back(i);
        }
    }

    ll cnt = 0;

    sort(st.begin(), st.end());


    for(i = 0; i < st.size(); i++)
    {
        cnt += lower_bound(st.begin(), st.end(), ed[i]+1) - st.begin();
    }
    cout << n*n - cnt;
}
