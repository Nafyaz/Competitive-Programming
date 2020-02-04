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
    int T, i, j, flag, ans, c, x;
    string s, t;
    vector<int> pos[30];
    cin >> T;
    while(T--)
    {
        cin >> s >> t;
        for(i = 0; i < 30; i++)
            pos[i].clear();
        for(i = 0; i < s.size(); i++)
        {
            pos[s[i] - 'a'].push_back(i);
        }

        flag = 1, ans = 1, j = -1;
        for(i = 0; i < t.size(); i++)
        {
            c = t[i] - 'a';
            if(pos[c].size() == 0)
            {
                flag = 0;
                break;
            }

            x = upper_bound(pos[c].begin(), pos[c].end(), j) - pos[c].begin();
//            cout << x << " " << j << " ";
            if(x == pos[c].size())
            {
                j = -1;
                i--;
                ans++;
            }
            else
            {
                j = pos[c][x];
            }
//            cout << j << endl;
        }

        if(!flag)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}
