//Thanks to ikaadil
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

int a[100009], b[100009];
int main()
{
    int n, k, i, j, x, mx = -1;
    string s;

    cin >> n >> k >> s;

    for(i = 1; i <= n; i++)
    {
        a[i] += a[i-1] + (s[i-1] == 'a');
        b[i] += b[i-1] + (s[i-1] == 'b');
    }

    i = j = 1;

    while(i <= n && j <= n)
    {
        if(a[j] - a[i-1] <= k)
        {
            mx = max(mx, j-i+1);
            j++;
        }
        else
            i++;
    }

    i = j = 1;
    while(i <= n && j <= n)
    {
        if(b[j] - b[i-1] <= k)
        {
            mx = max(mx, j-i+1);
            j++;
        }

        else
            i++;
    }

    cout << mx;
}
