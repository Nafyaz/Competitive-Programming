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
    int i, j, n, k;
    cin >> n >> k;

    string x, y;
    cin >> x;

    y = x;

    for(i = 0; i < n-k; i++)
        y[i+k] = y[i];

    for(i = k-1; y < x; i--)
    {
        if(y[i] == '9')
            continue;
        else
            y[i]++;

        for(j = i+1; j < n; j++)
        {
            y[j] = '0';
        }
        for(j = 0; j < n-k; j++)
        {
            y[j+k] = y[j];
        }

    }

    cout << n << endl << y;
}
