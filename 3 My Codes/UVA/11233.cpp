#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l, n, sz;
    cin >> l >> n;

    string a, b;
    map<string, string> mp;

    while(l--)
    {
        cin >> a >> b;
        mp[a] = b;
    }

    while(n--)
    {
        cin >> a;

        sz = a.size();
        if(a.size() >= 2)
            b = a.substr(sz - 2, 2);

        if(mp.find(a) != mp.end())
            cout << mp[a] << endl;

        else if(sz >= 2 && a.back() == 'y' && a[sz-2] != 'a' && a[sz-2] != 'e' && a[sz-2] != 'i' && a[sz-2] != 'o' && a[sz-2] != 'u')
            cout << a.substr(0, sz - 1) << "ies\n";

        else if(a.back() == 'o' || a.back() == 's' || a.back() == 'x')
            cout << a << "es\n";

        else if(sz >= 2 && (b == "ch" || b == "sh"))
            cout << a << "es\n";

        else
            cout << a << "s\n";
    }
}
