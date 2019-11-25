#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int x = max(a, max(b, c));
    printf("%d", 9*x + a+b+c);
}
