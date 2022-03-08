#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> s;

        if(s.find('r') < s.find('R') && s.find('g') < s.find('G') && s.find('b') < s.find('B'))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
