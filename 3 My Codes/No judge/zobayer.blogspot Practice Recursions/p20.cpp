#include<bits/stdc++.h>
using namespace std;
int i = 1;
void TOH(int a, int b, int c, int n)
{
    if(n == 1)
    {
        printf("%d: %c -> %c\n", i++, 'A'+a, 'A'+c);
        return;
    }
    TOH(a, c, b, n - 1);
    printf("%d: %c -> %c\n", i++, 'A'+a, 'A'+c);
    TOH(b, a, c, n - 1);
}
int main()
{
    TOH(0, 1, 2, 4);
}
