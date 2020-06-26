#include<stdio.h>
#include<math.h>

double modulus(double n)
{
    if(n>=0)
    {
        return n;
    }
    else
    {
        n=-n;
        return n;
    }
}
int main()
{
    double x1,y1,r1,x2,y2,r2,a,b;
    scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);
    a=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    b=r1-r2;
    if(x1==x2&&y1==y2&&r1==r2)
    {
        printf("-1\n");
    }

    else if((r1+r2)==a||modulus(b)==a)
    {
        printf("1\n");
    }
    else if((r1+r2)<a)
    {
        printf("0\n");
    }
    else
    {
        printf("2\n");
    }
    return 0;




}
