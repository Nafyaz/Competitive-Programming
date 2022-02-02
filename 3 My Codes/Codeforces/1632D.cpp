#include<bits/stdc++.h>
using namespace std;
#define N 200005

int n;
int x[N];
int tree[4*N];

void build(int node, int s, int e)
{
    if(s == e)
    {
        tree[node] = x[s];
        return;
    }

    int mid = (s+e)/2;

    build(2*node, s, mid);
    build(2*node+1, mid+1, e);

    tree[node] = __gcd(tree[2*node], tree[2*node+1]);
}

void update(int node, int s, int e, int idx, int val)
{
    if(s == e)
    {
        tree[node] = val;
        x[idx] = val;
        return;
    }

    int mid = (s+e)/2;

    if(idx <= mid)
        update(2*node, s, mid, idx, val);
    else
        update(2*node+1, mid+1, e, idx, val);

    tree[node] = __gcd(tree[2*node], tree[2*node+1]);
}

int query(int node, int s, int e, int l, int r)
{
    if(l > e || r < s)
        return 0;

    if(l <= s && r >= e)
        return tree[node];

    int mid = (s+e)/2;
    int p1 = query(2*node, s, mid, l, r);
    int p2 = query(2*node+1, mid+1, e, l, r);

    return __gcd(p1, p2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, j, j2, lastChanged = 0, ans = 0;

    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> x[i];

    build(1, 1, n);

    for(i = 1; i <= n; i++)
    {
        if(x[i] == 1)
        {
            ans++;
            lastChanged = i;
            cout << ans << " ";
            continue;
        }

        for(j = 1; j*j <= x[i] && i-j+1 > lastChanged; j++)
        {
            if(x[i]%j == 0)
            {
                j2 = x[i]/j;
                if(query(1, 1, n, i-j+1, i) == j)
                {
                    ans++;
                    lastChanged = i;
                    update(1, 1, n, i, 1);
                    break;
                }
                else if(i-j2+1 > lastChanged && query(1, 1, n, i-j2+1, i) == j2)
                {
                    ans++;
                    lastChanged = i;
                    update(1, 1, n, i, 1);
                    break;
                }
            }
        }

        cout << ans << " ";
    }
}
