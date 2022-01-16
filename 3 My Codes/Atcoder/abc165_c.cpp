#include<bits/stdc++.h>
using namespace std;

int n, m, q, A[15], ans;
int a[55], b[55], c[55], d[55];

int FindAns()
{
    int i, ret = 0;
    for(i = 0; i < q; i++)
    {
        if(A[b[i]] - A[a[i]] == c[i])
            ret += d[i];
    }

    return ret;
}

void call(int idx, int Last)
{
    if(idx > n)
    {
        ans = max(ans, FindAns());
        return;
    }

    int i;
    for(i = Last; i <= m; i++)
    {
        A[idx] = i;
        call(idx+1, i);
    }
}

int main()
{
    int i;

    cin >> n >> m >> q;

    for(i = 0; i < q; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    call(1, 1);

    cout << ans;
}
