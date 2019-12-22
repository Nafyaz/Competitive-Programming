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
    int i, j;
    string s;
    cin >> s;

    int ans = 0, leftcount = 0, rightcount = 0;
    i = -1;
    j = s.size();

    while(i < j)
    {
        if(leftcount <= rightcount)
        {
            i++;
            if(s[i] == '{')
                leftcount++;
        }
        else
        {
            j--;
            if(s[j] == '}')
                rightcount++;
        }

        ans = max(ans, min(leftcount, rightcount));
    }

    cout << ans;
}
