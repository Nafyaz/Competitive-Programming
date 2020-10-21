#include<bits/stdc++.h>
using namespace std;

#define N 100009
int mobius[N], primechk[N];

void preprocess()
{
    int i, j;
    for(i = 1; i <= N; i++)
    {
        mobius[i] = 1;
        primechk[i] = 1;
    }

    primechk[1] = 0;
    for(i = 2; i <= N; i++)
    {
        if(primechk[i] == 1)
        {
            mobius[i] = -mobius[i];
            for(j = 2; i*j <= N; j++)
            {
                primechk[i*j] = 0;
                if(j%i == 0)
                    mobius[i*j] = 0;
                else
                    mobius[i*j] = -mobius[i*j];
            }
        }
    }
}

int main()
{

}
