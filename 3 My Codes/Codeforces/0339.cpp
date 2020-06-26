#include<bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template<typename T>
//using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

int n, a[200009], tree[800009], p, b;

void build(int s, int e, int node, int mode)
{
    if(s == e)
    {
        tree[node] = a[s];
        return;
    }

    int mid = (s+e)/2, left = 2*node+1, right = 2*node+2;

    build(s, mid, left, mode^1);
    build(mid+1, e, right, mode^1);

    if(mode)
        tree[node] = tree[left] | tree[right];
    else
        tree[node] = tree[left] ^ tree[right];
}

void update(int s, int e, int node, int mode)
{
    if(s == e)
    {
        a[s] = b;
        tree[node] = a[s];
        return;
    }

    int mid = (s+e)/2, left = 2*node+1, right = 2*node+2;

    if(p <= mid)
        update(s, mid, left, mode^1);
    else
        update(mid+1, e, right, mode^1);

    if(mode)
        tree[node] = tree[left] | tree[right];
    else
        tree[node] = tree[left] ^ tree[right];
}

int main()
{
    int i, m, mode;
    cin >> n >> m;
    mode = n&1;
    n = (1 << n);
    for(i = 0; i < n; i++)
        cin >> a[i];

    build(0, n-1, 0, mode);

//    for(i = 0; i < 20; i++)
//        cout << tree[i] << " ";

    while(m--)
    {
        cin >> p >> b;
        p--;
        update(0, n-1, 0, mode);
        cout << tree[0] << endl;
    }
}
