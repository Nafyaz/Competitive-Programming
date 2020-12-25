#include<bits/stdc++.h>
using namespace std;

#define sz 100009
int n, q, a[sz], lfreq[sz], rfreq[sz], tree[4*sz];

void build(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = lfreq[b];
        return;
    }

    int mid = (b+e)/2, left = 2*node, right = 2*node+1;

    build(left, b, mid);
    build(right, mid+1, e);

    int p1 = tree[left], p2 = tree[right];

    tree[node] = max(p1, p2);
}

int query(int node, int b, int e, int i, int j)
{
    if(b > j || e < i)
        return INT_MIN;
    if(b >= i && e <= j)
        return tree[node];

    int mid = (b+e)/2, left = 2*node, right = 2*node+1;

    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);

    return max(p1, p2);
}


int main()
{
    int i, l, r;
    while(1)
    {
        cin >> n;
        if(!n)
            break;
        cin >> q;

        for(i = 1; i <= n; i++)
        {
            cin >> a[i];
            if(i > 1 && a[i] == a[i-1])
                lfreq[i] = lfreq[i-1] + 1;
            else
                lfreq[i] = 1;
        }

        for(i = n; i >= 1; i--)
        {
            if(i < n && a[i] == a[i+1])
                rfreq[i] = rfreq[i+1] + 1;
            else
                rfreq[i] = 1;
        }

//        for(i = 1; i <= n; i++)
//            cout << lfreq[i] << " ";
//        cout << endl;
//        for(i = 1; i <= n; i++)
//            cout << rfreq[i] << " ";

        build(1, 1, n);

        while(q--)
        {
            cin >> l >> r;

            if(a[l] == a[r])
                cout << r - l + 1 << endl;
            else
                cout << max(rfreq[l], query(1, 1, n, l+rfreq[l], r)) << endl;
        }
    }
}
