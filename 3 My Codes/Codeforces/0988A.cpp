#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    pair<int, int> a[102];
    set<int> s;

    int n, k, i;

    cin >> n >> k;

    for(i = 0; i < n; i++)
    {
        cin >> a[i].ff;
        a[i].ss = i;
        s.insert(a[i].ff);
    }

    if(s.size() < k)
    {
        cout << "NO";
        return 0;
    }

    sort(a, a+n);

    cout << "YES\n";
    for(i = 0; i < n; i++)
    {
        if((i == 0 || a[i].ff != a[i-1].ff) && k)
        {
            cout << a[i].ss+1 << " ";
            k--;
        }
    }
}
