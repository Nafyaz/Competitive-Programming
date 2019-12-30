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

string b;
ll bvalue;

bool isDivisible(string a)
{
    if(a.size() == 0)
        return 1;
    ll i;
    for(i = 0; i < a.size(); i++)
    {
        if(a[i] != '0')
            break;
    }

    a = a.substr(i, a.size() - i);

    if(a.size() < b.size() || (a.size() == b.size() && a[0] < b[0]))
        return 0;

    string temp = a.substr(0, b.size());
    if(a[0] <)
}

int main()
{
    int t, caseno = 0, i;

    string a, b;

    cin >> t;

    while(t--)
    {
        cin >> a >> b;
        if(a[0] == '-')
            a = a.substr(1, a.size() - 1);
        if(b[0] == '-')
            b = b.substr(1, b.size() - 1);

        bvalue = 0;
        for(i = 0; i < b.size(); i++)
            bvalue = 10*bvalue + b[i] - '0';


        if(isDivisible(a))

    }
}
