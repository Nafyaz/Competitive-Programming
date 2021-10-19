#include<bits/stdc++.h>
using namespace std;

int Z[100];

void z_function(string s)
{
    int i, l, r, n = s.size();

    memset(Z, 0, sizeof Z);
    for(i = 1, l = 0, r = 0; i < n; i++)
    {
        if(i <= r)
            Z[i] = min(r-i+1, Z[i-l]);
        while(i+Z[i] < n && s[Z[i]] == s[i+Z[i]])
            Z[i]++;

        if(i+Z[i]-1 > r)
        {
            r = i+Z[i]-1;
            l = i;
        }
    }
}

int main()
{
//    freopen("out.txt", "w", stdout);

    int t, i, n, flag;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> s;
        n = s.size();

        z_function(s);

        flag = 1;
        for(i = 1; i < n; i++)
        {
            if(n%i == 0 && i+Z[i] == n)
            {
                cout << i << "\n";
                flag = 0;
                break;
            }
        }

        if(flag)
            cout << n << "\n";

        if(t)
            cout << "\n";
    }
}

/*
2

ccccacccca

ccc
*/
