// Tutorial dekhar por ei code lekhsi :'(
// er ager submission e amar solution :D
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int ax, ay, bx, by, cx, cy;
    scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);
    bx -= ax, cx -= ax;
    by -= ay, cy -= ay;

    if(bx > 0 && by > 0 && cx > 0 && cy > 0)
        printf("YES");
    else if(bx > 0 && by < 0 && cx > 0 && cy < 0)
        printf("YES");
    else if(bx < 0 && by > 0 && cx < 0 && cy > 0)
        printf("YES");
    else if(bx < 0 && by < 0 && cx < 0 && cy < 0)
        printf("YES");
    else
        printf("NO");
}
