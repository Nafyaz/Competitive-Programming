#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, balance[100005] = {0};
    map<int, int> mnIdx;
    string s;

    cin >> n >> s;

    int ans = 0;
    mnIdx[0] = 0;
    for(i = 1; i <= n; i++)
    {
        if(s[i-1] == '1')
            balance[i] = balance[i-1] + 1;
        else
            balance[i] = balance[i-1] - 1;

        if(mnIdx.find(balance[i]) == mnIdx.end())
            mnIdx[balance[i]] = i;
        else
            ans = max(ans, i - mnIdx[balance[i]]);
    }

    cout << ans;
}
