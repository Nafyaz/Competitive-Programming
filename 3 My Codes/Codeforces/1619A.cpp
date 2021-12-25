#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> s;

        if(s.substr(0, s.size()/2) == s.substr(s.size()/2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
