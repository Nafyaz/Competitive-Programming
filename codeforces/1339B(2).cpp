#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i, a[100009], ans[100009], l, r;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a+n);

        l = 0;
        r = n-1;
        i = 0;
        while(i < n)
        {
            ans[i++] = a[l++];
            if(i < n)
                ans[i++] = a[r--];
        }

        for(i = n-1; i >= 0; i--)
            cout << ans[i] << " ";
        cout << endl;
    }
}
