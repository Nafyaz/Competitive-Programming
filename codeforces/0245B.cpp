#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, flag = 1, len, j;
    char s[60];
    scanf("%s", s);
    len = strlen(s);
    for(i = 0; i < len; i++)
    {
        if(s[0] == 'h' && i == 4)
        {
            printf("://");
            j = i;
        }
        else if(s[0] == 'f' && i == 3)
        {
            printf("://");
            j = i;
        }
        if(s[i] == 'r' && s[i + 1] == 'u' && flag && i != j)
        {
            printf(".ru");
            i += 2;
            if(i >= len)
                return 0;
            printf("/");
            flag = 0;
        }
        printf("%c", s[i]);

    }
}
