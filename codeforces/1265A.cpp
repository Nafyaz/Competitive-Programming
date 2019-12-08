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
    int t, i, flag;
    string s;
    cin >> t;

    while(t--)
    {
        flag = 1;
        cin >> s;
        s = '?' + s + '?';
        for(i = 1; i < s.size() - 1; i++)
        {
            if(s[i] != '?' &&(s[i] == s[i-1] || s[i] == s[i+1]))
            {
                flag = 0;
                break;
            }
            if(s[i] == '?')
            {
                if(s[i-1] != 'a' && s[i+1] != 'a')
                    s[i] = 'a';
                if(s[i-1] != 'b' && s[i+1] != 'b')
                    s[i] = 'b';
                if(s[i-1] != 'c' && s[i+1] != 'c')
                    s[i] = 'c';
            }
        }

        cout << (flag? s.substr(1, s.size()-2) : "-1") << endl;
    }
}
