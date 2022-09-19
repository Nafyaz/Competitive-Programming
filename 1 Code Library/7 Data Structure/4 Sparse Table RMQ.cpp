ll arr[MAXN], sparse[MAXN][20], Log[MAXN];

ll query(ll bg, ll ed)
{
    ll k = Log[ed-bg+1];
    return min(sparse[bg][k], sparse[ed - (1 << k) + 1][k]);
}

void rmq_init()
{
    ll n, i, j;

    Log[1] = 0;
    for(i = 2; i < MAXN; i++)
        Log[i] = Log[i/2] + 1;

    cin >> n;
    for(i = 0; i <= n; i++)
        sparse[i][0] = arr[i];

    for(j = 1; j < 20; j++)
    {
        for(i = 0; i + (1LL << j) - 1 < n; i++)
            sparse[i][j] = min(sparse[i][j-1], sparse[i + (1LL << (j-1))][j-1]);
    }
}