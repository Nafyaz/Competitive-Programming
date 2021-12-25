#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

map<int, int> mp;
int a[500005];

int main()
{
    int T, n, i;

    cin >> T;

    while(T--)
    {
        cin >> n;

        set<int> s;

        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);

            mp[a[i]] = i;
        }

        if(n == 1 || s.size() != n)
        {
            cout << "YES\n";
            continue;
        }
        if(n == 2 && a[0] > a[1])
        {
            cout << "NO\n";
            continue;
        }


        for(i = 0; i+2 < n; i++)
        {
            int pos = *(mp.begin() + i).ss;
            if(pos == i)
                continue;
            if(a[])
        }
    }
}
