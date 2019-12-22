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
    int t, i;
    vector<int> v;
    string s, x, y;

    cin >> t;
    while(t--)
    {
        v.clear();
        cin >> s;
        for(i = 0; i < s.size();)
        {
            if(i <= s.size() - 5)
                x = s.substr(i, 5);

            if(i <= s.size() - 3)
                y = s.substr(i, 3);

            if(i <= s.size() - 5 && x == "twone")
            {
                v.push_back(i+3);
                i += 5;
            }
            else if(i <= s.size() - 3 && (y == "one" || y == "two"))
            {
                v.push_back(i+2);
                i += 3;
            }
            else
                i++;
        }

        cout << v.size() << endl;
        for(auto u : v)
            cout << u << " ";
        cout << endl;
    }
}
