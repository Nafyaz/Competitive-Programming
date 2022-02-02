#include<bits/stdc++.h>
using namespace std;

int Z[5003];

void z_function(string s)
{
    int i, l, r, n = s.size();

    Z[0] = Z[1] = 0;

    for(i = 1, l = r = 0; i < n; i++)
    {
        if(i <= r)
            Z[i] = min(r-i+1, Z[i-l]);

        while(i+Z[i] < n && s[Z[i]] == s[i+Z[i]])
            Z[i]++;

        if(i+Z[i]-1 > r)
        {
            l = i;
            r = i+Z[i]-1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, i;
    string s;

    cin >> n >> k >> s;

    z_function(s);

    for(i = 1; i < n; i++)
    {
        if(i+Z[i] < n && s[i+Z[i]] > s[Z[i]])
            break;
        else if(i+Z[i] == n)
            break;
    }

    s = s.substr(0, i);

    while(s.size() < k)
        s = s + s;

    while(s.size() > k)
        s.pop_back();

    cout << s;
}
