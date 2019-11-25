#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i <= b; i++)

int main()
{
    int n, i;
    scanf("%d\n", &n);
    char c;
    long long int sum = 0;

    FORAB(i, 1, n)
    {
        scanf("%c", &c);
        if((c - '0') % 2 == 0)
            sum += i;
    }
    printf("%I64d", sum);

}
