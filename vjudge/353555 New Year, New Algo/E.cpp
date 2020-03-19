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

ll a[100009];

void print(stack<ll> s)
{
    cout << "stack: ";
    while(!s.empty())
    {
        cout << a[s.top()] << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    ll t, caseno = 0, n, i, x, mx, temp;

    stack<ll> s;
//    cin >> t;

    while(1)
    {
        mx = 0;
        while(!s.empty())
            s.pop();
        s.push(0);

        scanf("%lld", &n);
        if(n == 0)
            break;

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
                    temp = s.top();
                    s.pop();
                    x = a[temp] * (i - s.top() - 1);
//                    cout << "area: " << x << endl;
                    mx = max(mx, x);
                }
                s.push(i);
            }
//
//            print(s);
        }

//        cout << "Case " << ++caseno << ": " << mx << endl;
        printf("%lld\n", mx);
    }
}

