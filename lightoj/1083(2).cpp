//Previous implementation with stack had an error, still got AC :/
//fixed it
#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

ll a[30009];

void print(stack<ll> s)
{
    stack<ll> s2 = s;
    cout << "stack:" << endl;
    while(!s.empty())
    {
        cout << setw(3) << s.top();
        s.pop();
    }
    cout << endl;
    while(!s2.empty())
    {
        cout << setw(3) << a[s2.top()];
        s2.pop();
    }
    cout << endl;
}

int main()
{
//    freopen("out.txt", "w", stdout);
    ll t, caseno = 0, n, i, x, mx, temp;

    stack<ll> s;
    scanf("%lld", &t);

    while(t--)
    {
        mx = INT_MIN;
        while(!s.empty())
            s.pop();
        s.push(0);

        scanf("%lld", &n);

        for(i = 1; i <= n+1; i++)
        {
            if(i <= n)
                scanf("%lld", &a[i]);
            else
                a[i] = 0;

            if(s.empty() || a[s.top()] <= a[i])
                s.push(i);
            else
            {
                while(a[s.top()] > a[i] && s.top() != 0)
                {
//                    if(a[s.top()] == a[i])
//                        break;
                    temp = s.top();
                    s.pop();
                    x = a[temp] * (i - s.top() - 1);
//                    cout << "area: " << x << endl;
                    mx = max(mx, x);
                }
                s.push(i);
            }
//
//            cout << "mx: " << mx << endl;
//            print(s);
        }

        printf("Case %lld: %lld\n", ++caseno, mx);
    }
}
