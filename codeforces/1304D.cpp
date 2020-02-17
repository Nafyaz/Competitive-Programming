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
    int t, n, i, j, k, mx[109], mn[109], low, high, templow;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        mx[0] = 0;
        low = -1;
        high = 1;
        for(i = 1; i < n; i++)
        {
            if(s[i-1] == '>')
            {
                mx[i] = low;
                low--;
            }
            else
            {
                mx[i] = high;
                high++;
            }
        }


        templow = low;
        i = 0;
        while(i < n)
        {
            if(mx[i] >= 0)
            {
                mn[i] = mx[i];
                i++;
                continue;
            }
            j = i;

            while(mx[j] < 0 && j < n)
            {
                j++;
            }
            k = j;
            j--;

            while(j >= i)
            {
                low++;
                mn[j] = low;
                j--;
            }
            i = k;
        }
        for(i = 0; i < n; i++)
            cout << mx[i] - templow<< " ";
        cout << endl;
        for(i = 0; i < n; i++)
            cout << mn[i] - templow<< " ";
        cout << endl;
    }
}
