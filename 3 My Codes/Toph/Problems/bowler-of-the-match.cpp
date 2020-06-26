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

struct bowler
{
    ll Over, Maiden_Over, Run, Wicket;
};

bool cmp(bowler a, bowler b)
{
    if(a.Wicket > b.Wicket)
        return 1;
    else if(a.Wicket < b.Wicket)
        return 0;

    if(a.Run < b.Run)
        return 1;
    else if(a.Run > b.Run)
        return 0;

    if(a.Maiden_Over > b.Maiden_Over)
        return 1;
    else if(a.Maiden_Over < b.Maiden_Over)
        return 0;

    if(a.Over < b.Over)
        return 1;
    else if(a.Over > b.Over)
        return 0;
}

int main()
{
    ll n, i, z = 0;
    char c;
    cin >> n;
    bowler p[n];
    for(i = 0; i < n; i++)
    {
        cin >> p[i].Over >> c >> p[i].Maiden_Over >> c >> p[i].Run >> c >> p[i].Wicket;
        if(p[i].Over == 0)
        {
            i--;
            n--;
            z++;
        }
    }
    sort(p, p+n, cmp);

    for(i = 0; i < n; i++)
        cout << p[i].Over << '-' << p[i].Maiden_Over << '-' << p[i].Run << '-' << p[i].Wicket << endl;
    while(z--)
        cout << "0-0-0-0" << endl;
}
