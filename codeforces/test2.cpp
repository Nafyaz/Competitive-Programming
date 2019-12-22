#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

int main()
{
    long long n,i,l,m,a[300008],b[300008];
    scanf("%I64d",&n);
    for(); i++<n; scanf("%I64d",a+i));
    for(i=0; i++<n; m+=a[i]>>1,1&a[i]?(l&&(1&(i^b[l-1]))?(--l,++m):b[l++]=i):0);
    printf("%I64d\n",m),exit(0);
}
