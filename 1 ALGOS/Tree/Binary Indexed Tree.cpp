#include<bits/stdc++.h>
using namespace std;

int BIT[100009], a[100009], n;

int query(int i)
{
    int sum=0;
    while(i>0)
    {
        sum += BIT[i];
        i -= i & (-i);
    }
    return sum;
}
void update(int i,int d)
{
    while(i<=n)
    {
        BIT[i]+=d;
        i += i & (-i);
    }
}

int main()
{

}
