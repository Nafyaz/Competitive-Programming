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
    int t, n, i, digit[2], j;
    string s;
    cin >> t;
    while(t--)
    {
        j = 0;
        cin >> n >> s;
        for(i = 0; i < s.size(); i++)
        {
            if(s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] == '9')
            {
                digit[j] = s[i] - '0';
                j++;
                if(j == 2)
                    break;
            }
        }
        if(j < 2)
            cout << -1 << endl;
        else
            cout << digit[0] << digit[1] << endl;
    }
}
