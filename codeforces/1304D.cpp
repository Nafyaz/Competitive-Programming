//thanks to DrSwad

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
    int t, n, i, j, k, mx[200009], mn[200009], low, high, templow;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        iota(mn, mn+n, 1);
        iota(mx, mx+n, 1);
        reverse(mn, mn+n);


        for(i = 0; i < n-1; i++)
        {
            if(s[i] == '>')
                continue;
            j = i;
            while(j < n-1 && s[j] == '<')
                j++;
            reverse(mn+i, mn+j+1);
            i = j;
        }

        for(i = 0; i < n-1; i++)
        {
            if(s[i] == '<')
                continue;
            j = i;
            while(j < n-1 && s[j] == '>')
                j++;
            reverse(mx+i, mx+j+1);
            i = j;
        }

        for(i = 0; i < n; i++)
            cout << mn[i] << " ";
        cout << endl;
        for(i = 0; i < n; i++)
            cout << mx[i] << " ";
        cout << endl;

    }
}
