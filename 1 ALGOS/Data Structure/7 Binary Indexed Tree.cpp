ll BIT[maxN], a[maxN], n;

void Update(ll i, ll d)
{
    while(i <= n)
    {
        BIT[i] += d;
        i += i & (-i);
    }
}

ll Query(ll i)
{
    ll sum=0;
    while(i > 0)
    {
        sum += BIT[i];
        i -= i & (-i);
    }
    
    return sum;
}

ll main()
{
    ll i;
    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }

    cout << "Sum of First 10 elements: " << query(10) << "\n";
    cout << "Sum of elements in [2, 7]: " << query(7) - query(1) << "\n";
}
