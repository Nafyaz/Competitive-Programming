#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

bool flag[2009];
void sieve()
{
    int i, j;
    flag[0] = flag[1] = 1;
    for(i = 4; i < 2009; i += 2)
        flag[i] = 1;

    for(i = 3; i * i < 2009; i += 2)
    {
        if(!flag[i])
        {
            for(j = i * i; j < 2009; j += 2 * i)
                flag[j] = 1;
        }
    }
}


int main()
{
    sieve();

    int t, i, caseno = 0;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        map<char, int> mp;
        for(i = 0; i < s.size(); i++)
            mp[s[i]]++;

        cout << "Case " << ++caseno << ": ";

        bool emp = 1;
        for(auto u : mp)
        {
            if(!flag[u.ss])
            {
                cout << u.ff;
                emp = 0;
            }
        }

        cout << (emp? "empty" : "") << endl;
    }
}
