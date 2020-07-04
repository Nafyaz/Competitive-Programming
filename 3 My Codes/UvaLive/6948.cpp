#include<bits/stdc++.h>
using namespace std;

bool taken[100];
vector<int> v;
string s;

bool check()
{
    int i, mx = *max_element(v.begin(), v.end());
    for(i = 1; i <= mx; i++)
    {
        if(taken[i] == 0)
            return 0;
    }
    return 1;
}

bool call(int i)
{
    if(i == s.size())
    {
        if(check())
            return 1;
        else
            return 0;
    }
    int a = s[i] - '0';

    if(taken[a] == 0)
    {
        taken[a] = 1;
        v.push_back(a);
        if(call(i+1))
            return 1;
        v.pop_back();
        taken[a] = 0;
    }

    if(i < s.size() - 1)
    {
        a = 10 * (s[i] - '0') + (s[i+1] - '0');
        if(taken[a] == 0)
        {
            taken[a] = 1;
            v.push_back(a);
            if(call(i+2))
                return 1;
            v.pop_back();
            taken[a] = 0;
        }
    }

    return 0;
}

int main()
{
    int i, t = 0;

    while(cin >> s)
    {
        memset(taken, 0, sizeof taken);
        v.clear();

        call(0);
        for(i = 0; i < v.size(); i++)
        {
            if(i != 0)
                cout << " ";
            cout << v[i];
        }
        cout << endl;
    }
}
