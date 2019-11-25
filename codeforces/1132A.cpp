#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    ((2*a + b + c) == (b + c + 2*d)) && (c <= 2*a)? printf("1") : printf("0");
}
