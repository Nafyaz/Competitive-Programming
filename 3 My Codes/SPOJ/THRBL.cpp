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

int sparse[50009][20], Log[50009];

int main()
{
    int n, m, i, j;
    cin >> n >> m;

    Log[1] = 0;
    for(i = 2; i <= n; i++)
        Log[i] = Log[i>>1] + 1;

    for(i = 0; i < n; i++)
        cin >> sparse[i][0];

    for(j = 1; (1 << j) <= n; j++)
    {
        for(i = 0; i + (1 << j) < n; i++)
            sparse[i][j] = max(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
    }

    int r, cnt = 0;
    while(m--)
    {
        cin >> i >> j;
        if(j <= i+1)
        {
            cnt++;
            continue;
        }
//        i--;
        j -= 2;
        r = Log[j-i+1];
        if(sparse[i-1][0] >= max(sparse[i][r], sparse[j - (1 << r) + 1][r]))
            cnt++;
//        cout << cnt << endl;
    }

    cout << cnt << endl;
}
