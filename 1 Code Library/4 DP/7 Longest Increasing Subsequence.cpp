ll n, last;
ll a[MAXN], p[MAXN];
ll dp[MAXN];

// O(nlogn)
ll getLIS()
{
    ll i, pos;
	vector<ll> dp;
	for (i = 0; i < n; i++)
    {
		pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
		if (pos == dp.size()) 
			dp.push_back(a[i]);
        else         
			dp[pos] = a[i];
	}
	return dp.size();
}

// O(n^2)
ll getLIS2()
{
    ll i, j;

    for(i = 0; i < n; i++)
        dp[i] = 1;

    for(i = 1; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(a[j] < a[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
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