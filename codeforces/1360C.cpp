#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, a[109], o, e, flag;
    cin >> t;
    while(t--)
    {
        cin >> n;
        o = e = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i]&1)
                o++;
            else
                e++;
        }
        if(o%2 == 0)
        {
            cout << "YES\n";
            continue;
        }

        flag = 0;
        sort(a, a+n);
        for(i = 1; i < n; i++)
        {
            if(a[i] - a[i-1] == 1)
            {
                cout << "YES\n";
                flag = 1;
                break;
            }
        }

        if(!flag)
            cout << "NO\n";
    }
}
