#include<bits/stdc++.h>
using namespace std;

int bigmod(int a, int b, int m)
{
    if(b == 0)
        return 1%m;
    int x, y;
    x = b&1 ? a%m : 1;
    y = bigmod(a, b/2, m);
    y = (y*y)%m;

    return (x*y)%m;
}


int main()
{

}
