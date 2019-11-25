#include<bits/stdc++.h>
using namespace std;
int dia[210][210], n;

int func(int total, int i, int j)
{
    if(i >= 2*n - 1)
        return total;
    if(j < 0)
        return 0;
    if(i < n && j > i)
        return 0;
    if(i >= n && j >= 2*n - 1 - i)
        return 0;

    total += dia[i][j];

    int p1, p2;

    if(i < n - 1)
    {
        p1 = func(total, i+1, j);
        p2 = func(total, i+1, j+1);
    }

    else
    {
        p1 = func(total, i+1, j-1);
        p2 = func(total, i+1, j);
    }

    return total + max(p1, p2);
}

int main()
{
    int T, caseno = 0, i, j, high;

    cin >> T;

    while(T--)
    {
        memset(dia, 0, sizeof(dia));
        cin >> n;
        for(i = 0; i < 2*n - 1; i++)
        {
            if(i < n)
            {
                for(j = 0; j <= i; j++)
                    cin >> dia[i][j];
            }
            else
            {
                for(j = 0; j < 2*n - 1 - i; j++)
                    cin >> dia[i][j];
            }
        }

        cout << func(0, 0, 0) << endl;
    }
}
/*
1
4
7
6 4
2 5 10
9 8 12 2
2 12 7
8 2
10
*/
