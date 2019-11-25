#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int i = 2, a[2] = {n/10, n%10};
    while(i--)
    {
        switch(a[i])
        {
        case 0:
            a[i] = 2;
            break;
        case 1:
            a[i] = 7;
            break;
        case 2:
            a[i] = 2;
            break;
        case 3:
            a[i] = 3;
            break;
        case 4:
            a[i] = 3;
            break;
        case 5:
            a[i] = 4;
            break;
        case 6:
            a[i] = 2;
            break;
        case 7:
            a[i] = 5;
            break;
        case 8:
            a[i] = 1;
            break;
        case 9:
            a[i] = 2;
        }
    }
    printf("%d", a[0]*a[1]);
}
