//Thanks to pranto1209
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, i;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> s;
        sort(s.begin(), s.end());

        if(s[0] != s[k-1])
            cout << s[k-1];
        else if(s[k] != s[n-1])
            cout << s.substr(k-1);
        else
        {
            for(i = 0; i < n; i += k)
                cout << s[i];
        }

        cout << endl;
    }
}
