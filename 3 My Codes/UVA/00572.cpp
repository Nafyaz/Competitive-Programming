#include<bits/stdc++.h>
using namespace std;

int m, n;
char field[1000][1000];

void func(int i, int j)
{
    if(i < 0 || i >= m || j < 0 || j >= n)
        return;

    if(field[i][j] == '*')
        return;

    field[i][j] = '*';

    func(i, j-1); func(i, j+1);
    func(i-1, j); func(i+1, j);

    func(i-1, j-1); func(i-1, j+1);
    func(i+1, j-1); func(i+1, j+1);
}

int main()
{
    //freopen("dot.txt", "w", stdout);
    int i, j, ans, c = 0;

    while(scanf("%d %d", &m, &n) == 2)
    {
        if(m == 0)
            break;

//        if(c)
//            printf("\n");
//        c++;

        ans = 0;
        for(i = 0; i < m; i++)
            scanf("%s", field[i]);

        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(field[i][j] == '@')
                {
                    ans++;
                    func(i, j);
                }
            }
        }

        printf("%d\n", ans);
    }
}

