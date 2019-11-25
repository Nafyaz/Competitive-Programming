#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, len;
    char s1[110], s2[110];
    scanf("%s %s", s1, s2);

    len = strlen(s1);

    for(i = 0; i < len; i++)
    {
        if(s1[i] >= 'a' && s1[i] <= 'z')
            s1[i] = s1[i] - 'a' + 'A';
        if(s2[i] >= 'a' && s2[i] <= 'z')
            s2[i] = s2[i] - 'a' + 'A';

        if(s1[i] < s2[i])
        {
            printf("-1");
            return 0;
        }
        else if(s1[i] > s2[i])
        {
            printf("1");
            return 0;
        }
    }
    printf("0");
}
