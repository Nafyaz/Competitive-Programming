#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> mp;
    int n;
    string s;
    cin >> n;

    while(n--)
    {
        cin >> s;
        if(mp.find(s) == mp.end())
        {
            mp[s] = 1;
            cout << "OK" << endl;
        }
        else
        {
            cout << s << mp[s] << endl;
            mp[s]++;
        }
    }
}
