#include<bits/stdc++.h>
using namespace std;

int lcs[1009][1009], vis[1009][1009], caseno;
string a, b;

int call(int i, int j)
{
    if(i == (int)a.size() || j == (int)b.size())
        return 0;
    if(vis[i][j] == caseno)
        return lcs[i][j];

    vis[i][j] = caseno;

    if(a[i] == b[j])
        return lcs[i][j] = 1 + call(i+1, j+1);
    else
        return lcs[i][j] = max(call(i+1, j), call(i, j+1));
}

int main()
{
    while(getline(cin, a))
    {
        getline(cin, b);
        caseno++;
        cout << call(0, 0) << "\n";
    }
}
