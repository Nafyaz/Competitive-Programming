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
    ll t, i, n, p, x, idx, flag;
    vector<int> d;
    cin >> t;
    while(t--)
    {
        d.clear();
        cin >> n >> p;
        for(i = 0; i < n; i++)
        {
            cin >> x;
            d.push_back(x);
        }

        idx = -1;
        flag = 0;
        d.push_back(p);
        for(i = 0; i < n; i++)
        {
            if(p%d[i] != 0)
            {
                flag = 1;
                idx = i;
                break;
            }

            if(d[i+1] % d[i] != 0 && p%d[i+1] == 0)
            {
                flag = 2;
                idx = i;
                break;
            }
        }

        if(flag == 0)
            cout << "NO" << endl;
        else if(flag == 1)
        {
            cout << "YES ";
            for(i = 0; i < n; i++)
            {
                if(i != idx)
                    cout << "0 ";
                else
                    cout << p/d[i] + 1 << " ";
            }
            cout << endl;
        }
        else if(flag == 2)
        {
            cout << "YES ";
            for(i = 0; i < n; i++)
            {
                if(i != idx && i != idx + 1)
                    cout << "0 ";
                else if(i == idx)
                    cout << d[i+1]/d[i] + 1 << " ";
                else if(i == idx+1)
                    cout << p/d[i] - 1 << " ";
            }
            cout << endl;
        }
    }
}
