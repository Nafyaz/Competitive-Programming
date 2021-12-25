#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    int g, s, b, mxg = -1, mxs = -1, mxb = -1;
    string name, mxname = "";

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> g >> s >> b;
        getline(cin, name);
        name = name.substr(1);

        if(g > mxg)
        {
            mxg = g;
            mxs = s;
            mxb = b;
            mxname = name;
        }
        if(g == mxg && s > mxs)
        {
            mxs = s;
            mxb = b;
            mxname = name;
        }
        if(g == mxg && s == mxs && b > mxb)
        {
            mxb = b;
            mxname = name;
        }
    }

    cout << mxname;
}
