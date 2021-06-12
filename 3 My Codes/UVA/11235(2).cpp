#include<bits/stdc++.h>
using namespace std;

#define sz 100009

int a[sz], lfreq[sz], rfreq[sz];

int sparse[sz][20], Log[sz];

int main()
{
    int n, q, i, j, l, r;

    Log[1] = 0;
    for(i = 2; i < sz; i++)
        Log[i] = Log[i>>1] + 1;

    while(1)
    {
        cin >> n;

        if(!n)
            break;

        cin >> q;

        for(i = 1; i <= n; i++)
        {
            cin >> a[i];

            if(i > 1 && a[i] == a[i-1])
                lfreq[i] = lfreq[i-1] + 1;
            else
                lfreq[i] = 1;
        }

        for(i = n; i >= 1; i--)
        {
            if(i < n && a[i] == a[i+1])
                rfreq[i] = rfreq[i+1] + 1;
            else
                rfreq[i] = 1;
        }

        for(i = 1; i <= n; i++)
            sparse[i][0] = lfreq[i];

        for(j = 1; (1<<j) <= n; j++)
        {
            for(i = 1; i + (1<<j) - 1 <= n; i++)
                sparse[i][j] = max(sparse[i][j-1], sparse[i+(1<<(j-1))][j-1]);
        }

//        for(i = 1; i <= n; i++)
//        {
//            for(j = 0; j <= 3; j++)
//                cout << sparse[i][j] << " ";
//            cout << "\n";
//        }

        while(q--)
        {
            cin >> l >> r;

            if(a[l] == a[r])
                cout << r-l+1 << "\n";
            else
            {
                int st = l+rfreq[l];
                int ed = r;
                int dist = Log[ed-st+1];

//                cout << st << " " << ed << " " << dist << "\n";

                cout << max(rfreq[l], max(sparse[st][dist], sparse[ed-(1<<dist)+1][dist])) << "\n";
            }
        }
    }
}
