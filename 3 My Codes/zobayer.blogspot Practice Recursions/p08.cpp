#include<bits/stdc++.h>
using namespace std;

bool rec(int i, int n)
{
    if(n == 1)
        return 1;
    if(i > sqrt(n))
        return 0;
    if(n % i == 0)
        return 1;

    return rec(i + 1, n);
}
int main()
{
    int n;

    scanf("%d", &n);
    rec(2, n) == 0? printf("prime\n") : printf("not prime\n");
}
