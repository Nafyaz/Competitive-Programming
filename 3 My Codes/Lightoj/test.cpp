#include <iostream>
#include<cmath>

using namespace std;
int main()
{
    int u,t;
    cin>>t;
    long double pie=3.141592653589;
    for(u=0; u<t; u++)
    {
        double r,w,q,d,p,l,n,c;
        int j;
        cin>>l >>n >>c;
        d=(1+(n*c));
        p=(2*pie);
        if(n!=0)
        {
            for(j=0;; j++)
            {
                q=p-((2*d*sin(p/2))-p)/(d*cos(p/2)-1);
                if(abs(p-q)<1e-7)
                {
                    break;
                }
                else
                {
                    p=q;
                }
            }
            r=(l/(2*sin(p/2)));
            w=r-sqrt((r*r)-((l*l)/4));
            printf("Case %d: %.10f\n",u+1,w);
        }
        else
        {
            printf("Case %d: 0\n",u+1);
        }
    }
    return 0;
}
