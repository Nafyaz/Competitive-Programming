#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, c;
    char s1, s2;
    scanf("%d", &n);
    while(n--)
    {
        c = 0;
        getchar();
        scanf("%c %c", &s1, &s2);
        s1 = s1 - 'a' + 1;
        s2 = s2 - '0';

        if(s1 + 2 <= 8 && s2 + 1 <= 8)
            c++;
        if(s1 + 2 <= 8 && s2 - 1 >= 1)
            c++;
        if(s1 + 1 <= 8 && s2 + 2 <= 8)
            c++;
        if(s1 - 1 >= 1 && s2 + 2 <= 8)
            c++;
        if(s1 - 2 >= 1 && s2 + 1 <= 8)
            c++;
        if(s1 - 2 >= 1 && s2 - 1 >= 1)
            c++;
        if(s1 - 1 >= 1 && s2 - 2 >= 1)
            c++;
        if(s1 + 1 <= 8 && s2 - 2 >= 1)
            c++;

        printf("%d\n",c);
    }
}
