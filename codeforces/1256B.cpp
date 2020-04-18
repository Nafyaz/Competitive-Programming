#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q, n, i, st, ed, mn[109], a[109];
    cin >> q;
    while(q--)
    {
        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> a[i];

        a[n+1] = 200;
        mn[n+1] = n+1;
        for(i = n; i > 0; i--)
        {
            if(a[i] > a[mn[i+1]])
                mn[i] = mn[i+1];
            else
                mn[i] = i;
//            cout << mn[i] << " ";
        }

//        cout << endl;

        st = 1;
        while(st <= n)
        {
            if(a[st] < a[mn[st+1]])
            {
                mn[st] = st;
                st++;
            }
            else if(a[st] > a[mn[st+1]])
                mn[st] = mn[st+1];

            ed = mn[st];
//            cout << st << endl;
            for(i = ed; i > st; i--)
                swap(a[i], a[i-1]);
            st = ed;
        }

        for(i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
