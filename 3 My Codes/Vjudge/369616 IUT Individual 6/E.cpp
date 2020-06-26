#include<bits/stdc++.h>
using namespace std;

map<string, string> mp;

int main()
{
    int n, q;
    string s, t;

    cin >> n;
    getline(cin, s);
    for(int i = 1; i <= n; i++)
    {
        getline(cin, s);
        getline(cin, t);
        mp[s] = t;
//        cout << s << "*" << t << endl;
    }

    cin >> q;
    getline(cin, s);
    while(q--)
    {
        getline(cin, s);
        cout << mp[s] << endl;
    }
}
/*
3
ko te kader molla
tui rajakar tui rajakar
tumi ke ami ke
garo chakma bangali
jalo re jalo
agun jalo
2
jalo re jalo
ko te kader molla
*/
