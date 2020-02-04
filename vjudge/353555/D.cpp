#include<bits/stdc++.h>
using namespace std;

map<string, int> s2i;
map<int, string> i2s;

vector<int> adj[20009];

int main()
{
    int i = 0, n;
    string s;
    while(1)
    {
        cin >> s;
        if(s == "--")
            break;
        s2i[s] = ++i;
        i2s[i] = s;
    }

    n = i;

    for(i = 1; i <= n; i++)
    {

    }

}
