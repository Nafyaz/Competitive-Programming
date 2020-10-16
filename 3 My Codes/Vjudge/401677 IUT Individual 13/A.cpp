#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, n, m, i, u[10009], v[10009], avail[1009];
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i = 0; i < m; i++)
        {
            cin >> u[i] >> v[i];
        }

        memset(avail, 0, sizeof avail);

        stack<ll> st;
        for(i = m-1; i >= 0; i--)
        {
            if(!avail[u[i]] && !avail[v[i]])
            {
                avail[u[i]] = 1;
                avail[v[i]] = 1;
                st.push(i);
            }
        }

        while(!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }

        cout << "\n";
    }
}
