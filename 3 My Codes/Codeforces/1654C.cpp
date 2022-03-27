#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, i, sum, p, flag;

    cin >> t;

    while(t--)
    {
        cin >> n;

        sum = 0;
        map<ll, ll> freq;

        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            freq[a[i]]++;
        }

        stack<ll> stk;
        stk.push(sum);

        flag = 1;
        while(!stk.empty())
        {
            p = stk.top();
            stk.pop();

            if(freq.find(p) != freq.end() && freq[p] >= 1)
                freq[p]--;
            else if(p == 1)
            {
                flag = 0;
                break;
            }
            else
            {
                stk.push(p/2);
                stk.push((p+1)/2);
            }
        }

        cout << (flag? "YES\n" : "NO\n");
    }
}
