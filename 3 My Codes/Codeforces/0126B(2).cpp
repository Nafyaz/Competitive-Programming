#include<bits/stdc++.h>
using namespace std;

string s;
int Z[1000006];

void z_function()
{
    int i, l, r, n = s.size();

    Z[0] = 0;
    for(i = 1, l = 0, r = 0; i < n; i++)
    {
        if(i <= r)
            Z[i] = min(r-i+1, Z[i-l]);
        while(i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
            Z[i]++;
        if(i + Z[i] > r)
        {
            l = i;
            r = i + Z[i] - 1;
        }
    }
}

int main()
{
    cin >> s;

    z_function();

    int i, n = s.size(), mx_middle = -1, ans = -1;

    for(i = 1; i < n; i++)
    {
        if(i + Z[i] == n)
        {
            mx_middle = max(mx_middle, Z[i] - 1);
        }
        else
            mx_middle = max(mx_middle, Z[i]);
    }

    for(i = 1; i < n; i++)
    {
        if(i + Z[i] == n && Z[i] <= mx_middle)
        {
            ans = Z[i];
            break;
        }
    }

    if(ans != -1)
        cout << s.substr(0, ans);
    else
        cout << "Just a legend";
}
