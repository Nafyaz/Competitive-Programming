#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i;
    string s[50009];

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> s[i];

        sort(s, s+n);

        for(i = 0; i < n; i++)
            cout << s[i] << "\n";
    }

}
