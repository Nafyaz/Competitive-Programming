#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, k, i, j, c = 0, len, a[11];
    char s[100];
    scanf("%d %d", &n, &k);
    FORAB(i, 0, n)
    {
        FORAB(j, 0, 10)
            a[j] = 0;

        scanf("%s", s);
        len = strlen(s);

        FORAB(j, 0, len)
            a[s[j] - '0'] = 1;

        FORAB(j, 0, k + 1)
            if(a[j] == 0)
            {
                c--;
                break;
            }
        c++;
    }
    printf("%d", c);
}
