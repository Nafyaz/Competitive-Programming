#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, len;
    char s[10000];
    bool quotepos = true; //true means at first. false means second

    while(gets(s))
    {
        len = strlen(s);

        for(i = 0; i < len; i++)
        {
            if(s[i] == '"' && quotepos)
            {
                printf("``");
                quotepos = false;
            }
            else if(s[i] == '"' )
            {
                printf("\'\'");
                quotepos =true;
            }
            else
                printf("%c", s[i]);
        }
        printf("\n");
    }
}
