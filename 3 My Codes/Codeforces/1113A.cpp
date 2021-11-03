#include<bits/stdc++.h>
using namespace std;

int n, v;
int dp[102][102];

int func(int currCap, int currCity)
{
    if(currCity == n)
        return 0;

    if(dp[currCap][currCity] != -1)
        return dp[currCap][currCity];

    int cost = INT_MAX;
    for(int i = 0; i <= v; i++)
    {
        if(currCap + i > 0 && currCap + i <= v)
            cost = min(cost, currCity*i + func(currCap+i-1, currCity + 1));
    }

    return dp[currCap][currCity] = cost;
}

int main()
{
    cin >> n >> v;

    memset(dp, -1, sizeof dp);

    cout << func(0, 1);
}
