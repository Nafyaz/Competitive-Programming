#include<bits/stdc++.h>
using namespace std;

int a[200009], n;

bool check(int m)
{
    int st = m, ed = n-1, last = 0;
    while(st <= ed)
    {
//        if(m == 3)
//            cout << st << " " << " " << ed << " " << last << endl;
        if(last > a[st] || last > a[ed])
            return 0;
        if(a[st] < a[ed])
        {
            last = a[st];
            st++;
        }
        else
        {
            last = a[ed];
            ed--;
        }
    }

    return 1;
}

int main()
{
    int t, i, ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i];

        int l = 0, h = n, m;

//        cout << check(3);

        while(l <= h)
        {
            m = (l + h) / 2;
            if(check(m))
            {
                ans = m;
                h = m-1;
            }
            else
                l = m+1;
        }

        cout << ans << endl;
    }
}
