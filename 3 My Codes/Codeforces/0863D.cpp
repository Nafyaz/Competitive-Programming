#include<bits/stdc++.h>
using namespace std;

int a[200005];
int t[200005], l[200005], r[200005];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n, q, m, i, j, b;

    cin >> n >> q >> m;

    for(i = 1; i <= n; i++)
        cin >> a[i];

    for(i = 1; i <= q; i++)
        cin >> t[i] >> l[i] >> r[i];

    while(m--)
    {
        cin >> b;

        for(i = q; i >= 1; i--)
        {
            if(b < l[i] || b > r[i])
                continue;
            if(t[i] == 1)
            {
                b--;
                if(b < l[i])
                    b = r[i];
            }
            else
                b = r[i] - b + l[i];

//            cout << i << ": " << b << "\n";
        }

        cout << a[b] << " ";
    }
}
/*
6 3 1
1 2 3 4 5 6
2 1 3
2 3 6
1 1 6
1
*/
