#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    n&1 ? printf("0") : printf("%d", 1 << (n/2));
}
