#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A = 0, F = 0, I = 0, n, i;
    char s[1000000];
    scanf("%d", &n);
    scanf("%s", s);

    for(i = 0; i < n; i++)
    {
        switch(s[i])
        {
        case 'A':
            A++;
            break;
        case 'F':
            F++;
            break;
        case 'I':
            I++;
            break;
        }
    }
    if(I > 1)
        printf("0");
    else if(I == 1)
        printf("1");
    else
        printf("%d", A);
}
