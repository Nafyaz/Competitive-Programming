// Always 1 indexed
LL n;
LL a[MAXN], BIT[MAXN];

void Update(LL i, LL d)
{
    while(i <= n)
    {
        BIT[i] += d;
        i += i & (-i);
    }
}

LL Query(LL i)
{
    LL sum = 0;
    while(i > 0)
    {
        sum += BIT[i];
        i -= i & (-i);
    }

    return sum;
}

// Add 7 in position 0
Update(0, 7);
// Add 20 in position 8
Update(8, 20);

cout << "Sum of First 10 elements: " << Query(10) << "\n";
cout << "Sum of elements in [2, 7]: " << Query(7) - query(1) << "\n";
