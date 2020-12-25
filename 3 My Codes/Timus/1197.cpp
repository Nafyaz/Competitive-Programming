#include<bits/stdc++.h>
using namespace std;

int dirx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int diry[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int call(int r, int c)
{
    int i, r2, c2, ret = 0;
    for(i = 0; i < 8; i++)
    {
        r2 = r + dirx[i];
        c2 = c + diry[i];
        if(r2 >= 0 && r2 < 8 && c2 >= 0 && c2 < 8)
            ret++;
    }

    return ret;
}

int main()
{
    int n, i;
    string s;

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> s;
        cout << call(s[0] - 'a', s[1] - '1') << "\n";
    }
}
