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

//  ALTERNATE
int sq;
int arr[30004];
pair<pii, int> query[200005];
int freq[1000006], ans[200005];
 
bool cmp(pair<pii, int> a, pair<pii, int> b)
{
    if(a.ff.ff/sq != b.ff.ff/sq)
        return a.ff.ff < b.ff.ff;
    
    return a.ff.ss < b.ff.ss;
}
 
void solve(int caseno)
{
    int n, i, q, l, r, distinct;
 
    cin >> n;
    sq = sqrt(n);
 
    for(i = 1; i <= n; i++)
        cin >> arr[i];
 
    cin >> q;
    for(i = 0; i < q; i++)    
    {
        cin >> query[i].ff.ff >> query[i].ff.ss;
        query[i].ss = i;
    }
 
    sort(query, query + q, cmp);
 
    distinct = 0;
    for(i = 0, l = 1, r = 0; i < q; i++)
    {
        while(r < query[i].ff.ss)
        {
            r++;
            if(freq[arr[r]] == 0)
                distinct ++;
            freq[arr[r]]++;
        }
        while(l > query[i].ff.ff)
        {
            l--;
            if(freq[arr[l]] == 0)
                distinct ++;
            freq[arr[l]]++;
        }
 
        while(l < query[i].ff.ff)
        {
            if(freq[arr[l]] == 1)
                distinct --;
            freq[arr[l]] --;
 
            l++;            
        }
        while(r > query[i].ff.ss)
        {
            if(freq[arr[r]] == 1)
                distinct --;
            freq[arr[r]] --;
 
            r--;
        }
 
        ans[query[i].ss] = distinct;
    }
 
    for(i = 0; i < q; i++)
        cout << ans[i] << "\n";
}