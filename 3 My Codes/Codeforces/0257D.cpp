#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    int n, i;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    string s(n, '.');
    int sum = 0;
    for(i = n-1; i >= 0; i--)
    {
        if(sum >= 0)
        {
            sum -= a[i];
            s[i] = '-';
        }
        else
        {
            sum += a[i];
            s[i] = '+';
        }
    }

    if(sum >= 0)
    {
        cout << s;
        return 0;
    }

    for(i = 0; i < n; i++)
        cout << (s[i] == '+'? '-' : '+');
}
