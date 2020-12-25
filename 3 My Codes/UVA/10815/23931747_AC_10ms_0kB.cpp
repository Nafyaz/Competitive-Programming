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
    int i;
    string s, t;
    set<string> dict;

    while(cin >> s)
    {
        for(i = 0; i < s.size(); i++)
            s[i] = tolower(s[i]);

        t = "";

        for(i = 0; i < s.size(); i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
            {
                t += s[i];
            }
            else
            {
                if(t.size() > 0)
                    dict.insert(t);
                t = "";
            }

        }

        if(t.size() > 0)
            dict.insert(t);
    }

    for(auto u : dict)
        cout << u << endl;
}
