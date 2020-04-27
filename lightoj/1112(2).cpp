#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, BIT[100009], a[100009];

ll query(ll i)
{
    ll ret = 0;
    while(i)
    {
        ret += BIT[i];
        i -= i&(-i);
    }
    return ret;
}

void update(ll i, ll d)
{
    while(i <= n)
    {
        BIT[i] += d;
        i += i&(-i);
    }

}

int main()
{
    ll t, q, i, j, v, type, caseno = 0;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &n, &q);
        for(i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            BIT[i] = 0;
        }

        for(i = 1; i <= n; i++)
            update(i, a[i]);

        printf("Case %lld:\n", ++caseno);
        while(q--)
        {
            scanf("%lld", &type);
            if(type == 1)
            {
                scanf("%lld", &i);
                i++;
                printf("%lld\n", a[i]);
                update(i, -a[i]);
                a[i] = 0;
            }
            else if(type == 2)
            {
                scanf("%lld %lld", &i, &v);
                i++;
                update(i, v);
                a[i] += v;
            }
            else
            {
                scanf("%lld %lld", &i, &j);
                i++, j++;
                printf("%lld\n", query(j) - query(i-1));
            }

//            for(i = 1; i <= n; i++)
//                cout << a[i] << " ";
//            cout << endl;
//            for(i = 1; i <= n; i++)
//                cout << BIT[i] << " ";
//            cout << endl;
        }
    }
}
