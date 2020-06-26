#include<bits/stdc++.h>
using namespace std;

int n, m;
string s, num = "0123456789";
vector<string> d;

bool cmp(string a, string b)
{
    string x = a, y = b;
    for(int i = 0; i < x.size(); i++)
    {
        if(x[i] >= '0' && x[i] <= '9')
            x[i] = x[i] - '0' + '{';
    }
    for(int i = 0; i < y.size(); i++)
    {
        if(y[i] >= '0' && y[i] <= '9')
            y[i] = y[i] - '0' + '{';
    }

    return x < y;
}

void func(int i, string ans)
{
//    cout << i << " " << ans << endl;
    if(i == s.size())
    {
        cout << ans << endl;
        return;
    }
    if(s[i] == '#')
    {
        for(int j = 0; j < n; j++)
            func(i+1, ans + d[j]);
    }
    else
    {
        for(int j = 0; j < 10; j++)
            func(i+1, ans + num[j]);
    }
}


int main()
{
    int i, j;

    while(cin >> n)
    {
//        cout << "n: " << n << endl;
        d.clear();

        for(i = 0; i < n; i++)
        {
            cin >> s;
            d.push_back(s);
        }

        sort(d.begin(), d.end(), cmp);

        cin >> m;
        cout << "--\n";
        for(i = 0; i < m; i++)
        {
            cin >> s;
            func(0, "");
        }
    }
}
