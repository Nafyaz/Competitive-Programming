#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, x, y, k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &x, &y, &k);
        ((x + y) / k) & 1 ? printf("Paja\n") : printf("Chef\n");
    }
}
