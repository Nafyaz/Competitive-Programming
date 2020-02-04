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
    int t, n, i, left, right;
    int a[300009];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i];

        left = n-1;
        for(i = 0; i < n; i++)
        {
            if(a[i] < i)
            {
                left = i-1;
                break;
            }
        }

        right = 0;
        for(i = n-1; i >= 0; i--)
        {
            if(a[i] < n-i-1)
            {
                right = i+1;
                break;
            }
        }

        if(left < right)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}
