ll a[MAXN], p[MAXN], n, last;

ll getLIS()
{
    ll i, j;

    for(i = 0; i < n; i++)
        dp[i] = 1;

    for(i = 1; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(a[j] <= a[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j];
                p[i] = j;
            }
        }
    }

    ll ret = 0, last = -1;
    for(i = 0; i < n; i++)
    {
        if(ret < dp[i])
        {
            ret = dp[i];
            last = i;
        }
    }

    return ret;
}