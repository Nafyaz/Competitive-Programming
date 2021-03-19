#include<bits/stdc++.h>
using namespace std;

int dp[10000009];

int func(int k)
{
    if(dp[k] != -1)
        return dp[k];


}

int main()
{
    int t, caseno = 0, k, i;

    cin >> t;

    while(t--)
    {
        cin >> k;

        for(i = 0; i <= k; i++)
            dp[i] = -1;


    }
}
