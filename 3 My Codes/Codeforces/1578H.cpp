#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll closing[10004];
ll opening[10004];

ll order(ll i, ll j)
{
    if(i+1 == j)
        return 0;
    if(closing[i] == j)
        return order(i+1, j-1);

    return max(order(i, closing[i])+1, order(closing[i]+3, j));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, n;
    string s;

    cin >> s;
    n = s.size();

    stack<ll> st;

    for(i = 0; i < n; i++)
    {
        if(s[i] == '(')
            st.push(i);
        else if(s[i] == ')')
        {
            closing[st.top()] = i;
            opening[i] = st.top();
            st.pop();
        }
    }

    cout << order(0, n-1);
}
