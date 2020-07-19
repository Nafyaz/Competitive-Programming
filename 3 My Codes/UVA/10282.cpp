#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a, b, line;
    map<string, string> mp;
    while(getline(cin, line))
    {
        if(line == "")
            break;
        stringstream ss;
        ss << line;
        ss >> a >> b;

        mp[b] = a;
    }

    while(cin >> a)
    {
        if(mp.find(a) != mp.end())
            cout << mp[a] << "\n";
        else
            cout << "eh\n";
    }
}
