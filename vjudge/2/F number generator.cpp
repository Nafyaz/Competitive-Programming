#include<bits/stdc++.h>
using namespace std;
int main()
{

    unsigned int n = 4;
    int i;
    for(i = 1; i <= 31; i+=3)
    {
        n = n + (1<<i);
    }
    printf("%u", n);
}
