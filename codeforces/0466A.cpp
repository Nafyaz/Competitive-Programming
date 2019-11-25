#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);

    printf("%d", min(n*a, n/m*b + (n%m)*a));
}
