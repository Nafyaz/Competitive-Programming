#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, t, i, l, r, j;
    char s[110];
    scanf("%d", &t);
    FORAB(i, 0, t)
    {
        scanf("%d\n", &n);
        scanf("%s", s);

        l = 0, r = 0;
        j = 0;
        while(s[j] == '<' && j < n)
            j++;
        l = j;
        j = 0;
        while(s[n - j - 1] == '>' && j < n)
            j++;
        r = j;
        printf("%d\n", min(l, r));
    }
}
