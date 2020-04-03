#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

map<int, int> mp;
bool B[1000009];

int main()
{
    int i, j, n, A, c, Acount = 0;
    for(i = 0; i < 1000009; i++)
        B[i] = 1;

    cin >> n >> A;

    for(i = 0; i < n; i++)
    {
        cin >> c;
        if(c != A)
        {
            if(mp[c] < Acount)
                B[c] = false;
            mp[c]++;
        }
        else
        {
            Acount++;
        }
    }

    for(auto u : mp)
    {
        if(u.ss >= Acount && B[u.ff] == 1)
        {
            cout << u.ff;
            return 0;
        }
    }

    cout << -1;
}
