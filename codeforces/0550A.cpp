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
    int i, ab1, ab2, ba1, ba2;
    string s;

    cin >> s;

    ab1 = ab2 = ba1 = ba2 = -1;
    for(i = 0; i < s.size()-1; i++)
    {
        if(s[i] == 'A' && s[i+1] == 'B')
        {
            if(ab1 == -1)
                ab1 = i;
            ab2 = i;
        }
        if(s[i] == 'B' && s[i+1] == 'A')
        {
            if(ba1 == -1)
                ba1 = i;
            ba2 = i;
        }
    }

    if(ab1 == -1 || ba1 == -1)
    {
        cout << "NO";
        return 0;
    }

    if(abs(ab1 - ba2) > 1)
    {
        cout << "YES";
        return 0;
    }

    if(abs(ab2 - ba1) > 1)
    {
        cout << "YES";
        return 0;
    }

    cout << "NO";
}
