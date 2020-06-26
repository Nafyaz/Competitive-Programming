#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main()
{
    int t, n, m, k, i, j, a[1009], flag;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        set<int> s;
        flag = 1;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
            if(s.size() > k)
                flag = 0;
        }

        if(!flag)
        {
            cout << -1 << endl;
            continue;
        }

        vector<int> b;
        for(auto u : s)
            b.pb(u);

        cout << n*k << endl;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < k; j++)
            {
                if(j < b.size())
                    cout << b[j] << " ";
                else
                    cout << "1 ";
            }
        }
        cout << endl;
    }
}
