#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x, y;
    scanf("%d %d", &x, &y);

    int x1, y2;

    x1 = abs(x) + abs(y);
    y2 = abs(x) + abs(y);

    x < 0? x1 = -x1 : x1 = x1;
    y < 0? y2 = -y2 : y2 = y2;

    if(x1 < 0)
        printf("%d 0 0 %d", x1, y2);
    else
        printf("0 %d %d 0", y2, x1);
}
