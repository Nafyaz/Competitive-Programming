#include<bits/stdc++.h>
using namespace std;

double a[100005], t1[100005], t2[100005];

int main()
{
    int T, n, i, p;
    double l, v, v1, v2, ans;

    cin >> T;

    while(T--)
    {
        cin >> n >> l;
        for(i = 1; i <= n; i++)
            cin >> a[i];
        a[0] = 0;
        a[n+1] = l;

        v = 1;
        t1[0] = 0;
        for(i = 1; i <= n; i++)
        {
            t1[i] = t1[i-1] + (a[i] - a[i-1])/v;
            v++;
        }
        t1[n+1] = t1[n] + (l - a[n])/v;


        v = 1;
        t2[n+1] = 0;
        for(i = n; i >= 1; i--)
        {
            t2[i] = t2[i+1] + (a[i+1] - a[i])/v;
            v++;
        }
        t2[0] = t2[1] + (a[1])/v;

//        for(i = 0; i <= n+1; i++)
//            cout << setw(9) << t1[i] << " ";
//        cout << "\n";
//        for(i = 0; i <= n+1; i++)
//            cout << setw(9) << t2[i] << " ";
//        cout << "\n";

        for(i = 0; i <= n; i++)
        {
            if(max(t1[i], t2[i+1]) <= min(t1[i+1], t2[i]))
            {
                p = i;
                break;
            }
        }

        v1 = p+1;
        v2 = n-p+1;

        ans = (a[p+1] - a[p] + v1*t1[p] + v2*t2[p+1]) / (v1 + v2);
        cout << fixed << setprecision(7) << ans << "\n";
    }
}
