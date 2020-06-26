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

bool cmp(string x, string y)
{
    int i;
    for(i = 0; i < x.size() && i < y.size(); i++)
    {
        if(x[i] < y[i])
            return 1;
        if(x[i] > y[i])
            return -1;
    }

    if(i < x.size())
        return -1;
    if(i < y.size())
        return 1;
    return 0;
}

int main()
{
    int n, i;
    string s;
    multiset<string> orig, tren;
    cin >> n;
    while(n--)
    {
        cin >> s;
        if(s[0] == '#')
            tren.insert(s.substr(1, s.size() - 1));
        else
            orig.insert(s);
    }

    multiset<string> :: iterator o, t;
    o = orig.begin();
    t = tren.begin();

    vector<string> x, y;

    while(o != orig.end())
    {
        x.push_back(*o);
        o++;
        if(t != tren.end())
        {
            x.push_back(*t);
            t++;
        }
    }

    o = orig.begin();
    t = tren.begin();
    while(o != orig.end())
    {
        if(t != tren.end())
        {
            y.push_back(*t);
            t++;
        }
        y.push_back(*o);
        o++;
    }

    int flag = 0;
    for(i = 0; i < x.size(); i++)
    {
        if(cmp(x[i], y[i]) == 1)
        {
            flag = 1;
            break;
        }
        if(cmp(x[i], y[i]) == -1)
        {
            flag = 0;
            break;
        }
    }

    if(flag)
    {
        for(auto u : x)
            cout << u << " ";
    }
    else
    {
        for(auto u : y)
            cout << u << " ";
    }
}
