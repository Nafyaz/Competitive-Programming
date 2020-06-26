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

int a[100009], sparse[100009][20], Log[100009];

//int findmn(int i, int j)
//{
//    int k = Log[j-i+1];
//    return min(sparse[i][k], sparse[j - (1 << k) + 1][k]);
//}

int main()
{
    int t, n, m, k, i, j, left, right, free, mn, mx;

    Log[1] = 0;
    for(i = 2; i <= 100000; i++)
        Log[i] = Log[i>>1] + 1;

    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        for(i = 0; i < n; i++)
            cin >> a[i];

//        for(i = 0; i < n; i++)
//            sparse[i][0] = a[i];
//
//        for(j = 1; (1 << j) <= n; j++)
//        {
//            for(i = 0; i + (1 << j) - 1 < n; i++)
//            {
//                sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
//            }
//        }

        free = max(0, m-1-k);
        mx = INT_MIN;
        for(int it = 0; it <= k; it++)
        {
            left = it;
            right = n - k + it - 1;

            mn = INT_MAX;
            for(i = 0; i <= free; i++)
            {
                mn = min(mn, max(a[left + i], a[right - free + i -1]));
            }
            mx = max(mx, mn);
        }
        cout << mx << endl;
    }
}
