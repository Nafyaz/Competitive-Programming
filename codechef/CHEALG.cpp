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
    int t, a, b, i, j;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        a = j = 0;
        for(i = 0; i < s.size(); i++)
        {
            if(s[i] != s[j])
            {
                a += 1;
                a += (log10(i-j) + 1);
                j = i;
            }
        }
        a += 1;
        a += (log10(i-j) + 1);


//        cout << a << " " << s.size() << endl;
        if(a < s.size())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
