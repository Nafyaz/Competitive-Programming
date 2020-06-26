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
    int t, i, n, oo, oz, zo, zz;
    string s, x;
    map<string, int> mpoz, mpzo;
    vector<int> ans;

    cin >> t;

    while(t--)
    {
        mpoz.clear();
        mpzo.clear();
        oo = oz = zo = zz = 0;
        cin >> n;

        for(i = 0; i < n; i++)
        {
            cin >> s;
            if(s[0] == '1' && s[s.size()-1] == '1')
                oo++;
            if(s[0] == '1' && s[s.size()-1] == '0')
            {
                oz++;
                mpoz[s] = i+1;
            }
            if(s[0] == '0' && s[s.size()-1] == '1')
            {
                zo++;
                mpzo[s] = i+1;
            }
            if(s[0] == '0' && s[s.size()-1] == '0')
                zz++;
        }
        if(oo && zz && (!oz && !zo))
        {
            cout << -1 << endl;
            continue;
        }
        else if(abs(oz - zo) <= 1)
        {
            cout << 0 << endl << endl;
            continue;
        }

        ans.clear();
        if(oz < zo-1)
        {
            for(auto u : mpzo)
            {
                x = u.ff;
                reverse(x.begin(), x.end());
                if(mpoz.find(x) == mpoz.end())
                {
                    ans.push_back(mpzo[u.ff]);
                    mpoz[x] = mpzo[u.ff];
                    oz++;
                    mpzo[u.ff] = 0;
                    zo--;
                }

                if(oz >= zo-1)
                    break;
            }
        }
        if(zo < oz-1)
        {
            for(auto u : mpoz)
            {
                x = u.ff;
                reverse(x.begin(), x.end());
                if(mpzo.find(x) == mpzo.end())
                {
                    ans.push_back(mpoz[u.ff]);
                    mpzo[x] = mpoz[u.ff];
                    zo++;
                    mpoz[u.ff] = 0;
                    oz--;
                }

                if(zo >= oz-1)
                    break;
            }
        }

        cout << ans.size() << endl;
        for(auto u : ans)
            cout << u << " ";
        cout << endl;

    }
}
