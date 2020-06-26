//Another shitty solution
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
    int t, l, r, u, d, i;
    string s;
    cin >> t;
    while(t--)
    {
        l = r = u = d = 0;
        cin >> s;

        for(i = 0; i < s.size(); i++)
        {
            if(s[i] == 'L')
                l++;
            if(s[i] == 'R')
                r++;
            if(s[i] == 'U')
                u++;
            if(s[i] == 'D')
                d++;
        }

        if(l == 0)
            r = 0;
        if(r == 0)
            l = 0;
        if(d == 0)
            u = 0;
        if(u == 0)
            d = 0;

        l = r = min(l, r);
        u = d = min(u, d);

        if(l == 0 && u > 0)
            cout << 2 << endl << "UD" << endl;
        else if(l > 0 && u == 0)
            cout << 2 << endl << "LR" << endl;
        else if(l == 0 && u == 0)
            cout << 0 << endl << endl;
        else
        {
            s = "";
            while(l--)
                s += 'L';
            while(u--)
                s += 'U';
            while(r--)
                s += 'R';
            while(d--)
                s += 'D';
            cout << s.size() << endl << s << endl;
        }
    }
}
