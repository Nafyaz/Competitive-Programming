#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, i;
    scanf("%d ", &n);
    char ex[30];
    scanf("%s", ex);

    int fact = 1;
    k = strlen(ex);
    for(i = n; i > 0; i -= k)
        fact *= i;

    printf("%d", fact);
}
