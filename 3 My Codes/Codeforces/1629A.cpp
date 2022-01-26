#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, k, i;
    pair<int, int> a[102];

    cin >> T;

    while(T--)
    {
        cin >> n >> k;

        for(i = 0; i < n; i++)
            cin >> a[i].ff;
        for(i = 0; i < n; i++)
            cin >> a[i].ss;

        sort(a, a+n);

        for(i = 0; i < n; i++)
        {
            if(a[i].ff > k)
                break;

            k += a[i].ss;
        }

        cout << k << "\n";
    }
}
