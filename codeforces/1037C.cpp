#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, ans = 0;
    cin >> n;

    string a, b;
    cin >> a >> b;

    for(i = 0; i < n-1; i++)
    {
        if(a[i] == '0' && a[i+1] == '1' && b[i] == '1' && b[i+1] == '0')
        {
            a[i] = '1';
            a[i+1] = '0';
            ans++;
        }

        if(a[i] == '1' && a[i+1] == '0' && b[i] == '0' && b[i+1] == '1')
        {
            a[i] = '0';
            a[i+1] = '1';
            ans++;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(a[i] != b[i])
        {
            a[i] = b[i];
            ans++;
        }
    }

    cout << ans;
}
