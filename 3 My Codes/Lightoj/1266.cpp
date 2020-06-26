#include<bits/stdc++.h>
using namespace std;

int BIT[1009][1009], a[1009][1009];

int query(int x, int y)
{
    int y1, sum = 0;
    while(x)
    {
        y1 = y;
        while(y1)
        {
            sum += BIT[x][y1];
            y1 -= y1&(-y1);
        }
        x -= x&(-x);
    }

    return sum;
}

void update(int x, int y, int d)
{
    int y1;
    while(x < 1009)
    {
        y1 = y;
        while(y1 < 1009)
        {
            BIT[x][y1] += d;
            y1 += y1&(-y1);
        }
        x += x&(-x);
    }
}

int main()
{
    int t, type, caseno = 0, q, x1, y1, x2, y2, ans;
    scanf("%d", &t);
    while(t--)
    {
        memset(BIT, 0, sizeof BIT);
        memset(a, 0, sizeof a);

        scanf("%d", &q);
        printf("Case %d:\n", ++caseno);
        while(q--)
        {
            scanf("%d", &type);

            if(type)
            {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                x1++, y1++, x2++, y2++;
                ans = query(x2, y2) - query(x1-1, y2) - query(x2, y1-1) + query(x1-1, y1-1);
                printf("%d\n", ans);
            }
            else
            {
                scanf("%d %d", &x1, &y1);
                x1++, y1++;
                if(a[x1][y1])
                    continue;
                a[x1][y1] = 1;
                update(x1, y1, 1);
            }

//            for(y1 = 0; y1 <= 10; y1++)
//                cout << setw(4) << y1;
//            cout << endl;
//            for(x1 = 1; x1 <= 10; x1++)
//            {
//                cout << setw(3) << x1 << ":";
//                for(y1 = 1; y1 <= 10; y1++)
//                    cout << setw(4) << BIT[x1][y1];
//                cout << endl;
//            }
        }
    }
}
