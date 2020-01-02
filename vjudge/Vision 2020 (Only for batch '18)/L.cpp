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
    int i, type, idx;
    string s;

    cin >> s;
    reverse(s.begin(), s.end());

    if(s.back() == 'b' || s.back() == 'c')
    {
        cout << -1;
        return 0;
    }

    vector<pair<int, int> > v;

    while(s.size() != 0)
    {
        if(s.size() == 1)
        {
            v.push_back({1, 1});
            v.push_back({2, 2});
            v.push_back({4, 1});
            break;
        }
        if(s.size() > 1 && s[s.size() - 2] == 'a')
        {
            v.push_back({1, 1});
            v.push_back({2, 2});
            v.push_back({4, 1});
            s.pop_back();
        }

        else if(s.size() > 1 && s[s.size() - 2] == 'c')
        {
            v.push_back({1, 1});
            v.push_back({4, 1});
            s.pop_back();
            s.pop_back();
        }
        else if(s.size() > 1 && s[s.size() - 2] == 'b')
        {
            if(s.size() == 2)
            {
                v.push_back({2, 2});
                v.push_back({4, 1});
                break;
            }
            else if(s[s.size() - 3] == 'a')
            {
                v.push_back({2, 2});
                v.push_back({4, 1});
                s.pop_back();
                s.pop_back();
            }
            else if(s[s.size() - 3] == 'b')
            {
                cout << -1;
                return 0;

            }
            else if(s[s.size() - 3] == 'c')
            {
                v.push_back({4, 1});
                s.pop_back();
                s.pop_back();
                s.pop_back();
            }
        }
    }

    cout << v.size() << endl;
    for(i = 0; i < v.size(); i++)
        cout << v[i].ff << " " << v[i].ss << endl;
}
