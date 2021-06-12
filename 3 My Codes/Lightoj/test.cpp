//18321047
//method1
//Nuren
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int iter=0;

double f(double x)
{
    //double y=26*x+5*sin(2*x)-12*(cos(2*x))+12;
    //printf("%x %f\n",y);
    return 26*x+5*sin(2*x)-12*(cos(2*x))+12;
}

double method1(double xl,double xu, double tol)
{
    double xold=xl;
    while(1)
    {
        double xr=(xu+xl)/2;
        iter++;
        if(f(xr)*f(xu)>0)
            xu=xr;
        else if(f(xr)*f(xu)<0)
            xl=xr;
        else
            return xr;
        double error=abs((xr-xold/xr))*100;
        if(error<tol)
            return xr;
        else
            xold=xr;
    }
}

int main(void)
{
    double xl, xu , tol=1E-4, root;
    while(1)
    {
        printf("Please enter the lower limit xl from [-200,-100]: ");
        scanf("%lf", &xl);
        printf("Please enter the upper limit xu from [100,200]: ");
        scanf("%lf", &xu);
        //break;
        if(abs(xu-xl) < 1e-7 || f(xl)*f(xu)>0)
            printf("Invalid input data.\n");
        else
            break;
    }

    root= method1(xl,xu,tol);
    printf("Root of the equation %f and no of iteration %d\n", root, iter);
}
