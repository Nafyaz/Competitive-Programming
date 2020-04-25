#include<bits/stdc++.h>
using namespace std;

int BIT[100005];
int query(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum += BIT[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
void update(int idx,int val,int n)
{
    while(idx<=n)
    {
        BIT[idx]+=val;
        idx += idx & (-idx);
    }
}

int main()
{

}
