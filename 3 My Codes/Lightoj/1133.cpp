#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, caseno = 0, n, m, x, y, i, j;
    char c;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        vector <int> a(n);
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(i = 0; i < m; i++)
        {
            getchar();
            scanf("%c", &c);
            switch(c){
            case 'S':
                scanf("%d", &x);
                for(j = 0; j < n; j++)
                    a[j] += x;
                break;
            case 'M':
                scanf("%d", &x);
                for(j = 0; j < n; j++)
                    a[j] *= x;
                break;
            case 'D':
                scanf("%d", &x);
                for(j = 0; j < n; j++)
                    a[j] /= x;
                break;
            case 'R':
                reverse(a.begin(), a.end());
                break;
            case 'P':
                scanf("%d %d", &x, &y);
                swap(a[x], a[y]);}
        }
        printf("Case %d:\n", ++caseno);
        for(i = 0; i < n; i++)
        {
            if(i)
                printf(" ");
            printf("%d", a[i]);
        }
        printf("\n");
    }
}
