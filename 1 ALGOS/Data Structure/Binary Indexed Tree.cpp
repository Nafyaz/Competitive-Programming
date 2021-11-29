#include<bits/stdc++.h>
using namespace std;

int BIT[100005], a[100005], n;

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
    int i;
    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }

    cout << "Sum of First 10 elements: " << query(10) << "\n";
    cout << "Sum of elements in [2, 7]: " << query(7) - query(1) << "\n";
}
