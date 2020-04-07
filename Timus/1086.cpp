#include<bits/stdc++.h>
slenderusing namespace std;
bool isprime[1600];
void sieve(void)
{
    int i, j;
    isprime[2] = 1;
    for(i = 2; i < 400; i++)
    {
        for(j = 2; j < 400; j++)
        {
            isprime[i * j] = 1;

        }

    }
}
int main()
{
    int n, i;
    scanf("%d", &n);


}
