#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t, n, flag, i;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a+n);

        flag = 0;
        for(i = 1; i < n && !flag; i++)
        {
            if(a[i] - a[i-1] == 1 && (a[i]^a[i-1]) == 1)
                flag = 1;
        }

        cout << (flag? "Yes\n" : "No\n");
    }
}
