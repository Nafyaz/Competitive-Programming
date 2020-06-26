#include<bits/stdc++.h>
using namespace std;
int s(int a)
{
    int ans = 0;
    while(a)
    {
        ans += a%10;
        a = a/10;
    }
    return ans;
}
int main()
{
    int a;
    scanf("%d", &a);

    while(s(a) %4 != 0)
        a++;

    printf("%d", a);
}
