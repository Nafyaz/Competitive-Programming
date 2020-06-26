#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
bool is_it_prime(long long a)
{
    if(a==2||a==3)
        return 1;
    if(a<2)
        return 0;
    int root=sqrt(a);
    int i;
    for(i=2;i<=root;i++)
    {
        if(a%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int t;
    long long n,i,max_prime=0,root;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        root=sqrt(n);
        for(i=1;i<=root;i++)
        {
            if(n%i==0)
            {
                if(max_prime<i&&is_it_prime(i))
                    max_prime=i;

                if(max_prime<(n/i)&&is_it_prime(n/i))
                    max_prime=n/i;
            }
        }

        printf("%I64d\n",max_prime);
    }
}
