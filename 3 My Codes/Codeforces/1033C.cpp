#include<bits/stdc++.h>
using namespace std;

int n, dp[100005];
int a[100005];

bool call(int p)
{
    int i;

    if(dp[p] != -1)
        return dp[p];

    for(i = p%a[p]; i < n; i += a[p])
    {
        if(a[i] > a[p] && call(i) == 0)
            return (dp[p] = 1);
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    memset(dp, -1, sizeof dp);
    for(i = 0; i < n; i++)
    {
        if(call(i))
            cout << "A";
        else
            cout << "B";
    }
}
