#include<bits/stdc++.h>
using namespace std;
int func(int a,int b,int m)
{
    if(b==0)
        return 1;
    if(b==1)
        return a%m;
    int x=func(a,b/2,m);
    int y=1;
    if(b&1)
        y=a%m;
    return (((x*x)%m)*y)%m;
}
int main()
{
    int a[4] = {1, 2, 3, 4};
    for(v : a)
        cout << v;
}
