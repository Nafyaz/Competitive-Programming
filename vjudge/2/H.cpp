#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T, i, Ax, Ay, Bx, By, Cx, Cy, Dx, Dy, area;
    scanf("%d", &T);

    for(i = 1; i <= T; i++)
    {
        scanf("%d %d", &Ax, &Ay);
        scanf("%d %d", &Bx, &By);
        scanf("%d %d", &Cx, &Cy);

        Dx = Ax + Cx - Bx;
        Dy = Ay + Cy - By;

        area = abs(Ax*By - Ay*Bx + Bx*Cy - By*Cx + Cx*Ay - Cy*Ax);

        printf("Case %d: %d %d %d\n", i, Dx, Dy, area);
    }
}
