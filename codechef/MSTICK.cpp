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

double b[100009], mns[100009][20], mxs[100009][20], Log[100009];

int main()
{
    int n, i, j;
    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> b[i];
        mns[i][0] = b[i];
        mxs[i][0] = b[i];
    }

    for(j = 1; j < 20; j++)
    {
        for(i = 0; i + (1 << j) <= n; i++)
        {
            mns[i][j] = min(mns[i][j-1], mns[i + (1 << (j-1))][j-1]);
            mxs[i][j] = max(mxs[i][j-1], mxs[i + (1 << (j-1))][j-1]);
        }
    }

//    cout << "MIN:" << endl;
//    for(j = 0; j <= 5; j++)
//    {
//        for(i = 0; i < n; i++)
//            cout << mns[i][j] << "\t";
//        cout << endl;
//    }
//    cout << "MAX:" << endl;
//    for(j = 0; j <= 5; j++)
//    {
//        for(i = 0; i < n; i++)
//            cout << mxs[i][j] << "\t";
//        cout << endl;
//    }

    Log[1] = 0;
    for(i = 2; i <= n; i++)
        Log[i] = Log[i>>1] + 1;

    int q, l, r, k;
    double mx, mn;
    cin >> q;

    while(q--)
    {
        cin >> l >> r;

        k = Log[r-l+1];
        mn = min(mns[l][k], mns[r-(1<<k)+1][k]);
        mx = max(mxs[l][k], mxs[r-(1<<k)+1][k]);

        mx = mn + (mx - mn)/2.0;

        if(l > 0)
        {
            k = Log[l];
            mx = max({mx, mxs[0][k] + mn, mxs[l-(1<<k)][k] + mn});
        }

        if(r < n-1)
        {
            k = Log[n-r-1];
            mx = max({mx, mxs[r+1][k] + mn, mxs[n-(1<<k)][k] + mn});
        }

        cout << fixed;
        cout << setprecision(1) << mx << endl;
    }
}
