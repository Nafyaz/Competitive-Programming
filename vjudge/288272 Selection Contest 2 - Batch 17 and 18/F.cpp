#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    char s1[1010], s2[6], a[6], b[6], c[6], d[6];
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s %s", s1, s2);
        if(strstr(s1, s2))
            printf("good\n");
        else
        {
            a[0] = s2[1]; a[1] = s2[2]; a[2] = s2[3]; a[3] = '\0';
            b[0] = s2[0]; b[1] = s2[2]; b[2] = s2[3]; b[3] = '\0';
            c[0] = s2[0]; c[1] = s2[1]; c[2] = s2[3]; c[3] = '\0';
            d[0] = s2[0]; d[1] = s2[1]; d[2] = s2[2]; d[3] = '\0';

            if(strstr(s1, a) || strstr(s1, b) || strstr(s1, c) || strstr(s1, d))
                printf("almost good\n");
            else
                printf("none\n");
        }

    }
}
