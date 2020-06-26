#include<bits/stdc++.h>
using namespace std;

int n, BIT[200009];

int query(int i)
{
    int ret = 0;
    while(i)
    {
        ret += BIT[i];
        i -= i&(-i);
    }
    return ret;
}

void update(int i, int d)
{
    while(i <= n)
    {
        BIT[i] += d;
        i += i&(-i);
    }
}

int main()
{
//    freopen("out.txt", "w", stdout);
    int i, j, x, y, r, a[200009], caseno = 0;
    string s;

    while(1)
    {
        memset(BIT, 0, sizeof BIT);
        cin >> n;
        if(!n)
            break;

        for(i = 1; i <= n; i++)
            cin >> a[i];

        for(i = 1; i <= n; i++)
            update(i, a[i]);

        if(caseno)
            cout << endl;
        cout << "Case " << ++caseno << ":\n";
        while(1)
        {
            cin >> s;
            if(s == "END")
                break;
            if(s == "S")
            {
                cin >> x >> r;
                update(x, r-a[x]);
                a[x] = r;
            }
            else
            {
                cin >> x >> y;
                cout << query(y) - query(x-1) << endl;
            }
        }
    }
}
/*
M 1 1
M 1 2
M 1 3
M 2 2
M 2 3
M 3 3
*/
