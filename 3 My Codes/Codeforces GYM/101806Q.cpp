#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll pal[200005];
string s;
vector<ll> pos[26];



int main()
{
    ll q, p = 0, x;
    char c;

    cin >> q;
    getchar();

    while(q--)
    {
        cin >> c;

        if(c != '-')
        {
            s.push_back(c);

            x = c-'a';
            p++;

            pos[c-'a'].push_back(p);


        }

        else
        {
            s.pop_back();
            p--;
        }

    }
}
