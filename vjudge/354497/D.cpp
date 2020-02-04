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

vector<int> a;
vector<pair<int, int> > v;

int main()
{
    int t, n, k, i, j;
    cin >> t;
    while(t--)
    {
        a.clear();
        v.clear();
        cin >> n >> k;
        a = vector<int> (n);
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
//            a[i].ss = INT_MAX;
            v.push_back({a[i], i});
        }

        sort(v.begin(), v.end());
        int sorted = -1;

        for(i = 0; i < n; i++)
        {
            j = i;
            while(k >= v[j].ss - j && j > 0)
            {
                k --;
                j--;
                swap(a[j], a[j-1]);
                v[j-1].ss++;
                v[j].ss--;
                sorted = i;
            }
        }

        for(i = 0; i < n; i++)
            cout << a[i] << " ";
/*
        j = sorted+1;
        for(i = 0; i < n; i++)
        {
            if(a[i].ss == INT_MAX)
            {
                v[j] = {a[i].ff, i};
                j++;
            }
        }

        for(i = sorted+1; i < n && k; i++)
        {
            for(j = i-1; j > sorted && k; j--)
            {
                if(v[i].ff < v[j].ff)
                {
                    swap(v[i], v[j]);
                    k--;
                }
                else
                    break;
            }
        }

        for(i = sorted+1; i < n; i++)
            cout << v[i].ff << " ";
        cout << endl;
        */
    }
}

