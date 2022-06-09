ll arr[maxN], blocks[maxN];
void Init()
{    
    ll i, len = sqrt(n);
    for(i = 0; i < n; i++)
        blocks[i/len] += a[i];
}

ll Query(ll l, ll r)
{
    ll ret = 0;
    for(i = l; i <= r;)
    {
        if (i % len == 0 && i + len - 1 <= r)
        {
            sum += b[i / len];
            i += len;
        }
        else
        {
            sum += a[i];
            i++;
        }
    }

    return ret;
}