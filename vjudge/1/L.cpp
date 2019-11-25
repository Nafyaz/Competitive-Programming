#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    char s[100];
    scanf("%d\n", &n);
    while(n--)
    {
        scanf("%s", s);
        printf("%d\n", s[0] - '0' + s[strlen(s) - 1] - '0');
    }
}
