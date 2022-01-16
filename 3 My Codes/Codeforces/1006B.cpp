#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second


int main()
{
    int n, k, i, ans = 0;
    pair<int, int> a[2003];
    vector<int> v, upto, cnt;

    cin >> n >> k;

    for(i = 0; i < n; i++)
    {
        cin >> a[i].ff;
        a[i].ss = i+1;
    }

    sort(a, a+n);

    v.push_back(0);
    for(i = n-1; i >= n-k; i--)
    {
        v.push_back(a[i].ss);
        ans += a[i].ff;
    }

    sort(v.begin(), v.end());

    cout << ans << "\n";
    for(i = 1; i+1 < v.size(); i++)
        cout << v[i]-v[i-1] << " ";
    cout << n - v[k-1];
}
