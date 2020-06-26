#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, n, k, x, y;
    scanf("%d %d", &n, &k);
    char s[n+10];
    scanf("%s", s);
    x = y = (n - k)/2;
    for(i = 0; i < n; i++)
    {
        if(s[i] == '(' && x)
        {
            x--;
            continue;
        }
        if(s[i] == ')' && y)
        {
            y--;
            continue;
        }
        printf("%c", s[i]);
    }
}
