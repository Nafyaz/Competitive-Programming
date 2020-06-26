#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, n, t;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d %d", &a, &b, &n);
        switch (n%3)
        {
            case 0:
                printf("%d\n", a);
                break;
            case 1:
                printf("%d\n", b);
                break;
            case 2:
                printf("%d\n", a^b);
                break;
        }

    }
}
