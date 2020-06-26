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
    int n1,n2,stones=0,i,j,k,c,d,swap,z,x,y;
    int array[100009];
    scanf("%d",&n1);
    for(i=0; i<n1; i++)
    {
        scanf("%d",&n2);
        for(j=0; j<n2; j++)
        {
            scanf("%d",&array[j]);
        }

        for (c = 0 ; c < n2 - 1; c++)
        {
            for (d = 0 ; d < n2 - c - 1; d++)
            {
                if (array[d] < array[d+1])
                {
                    swap       = array[d];
                    array[d]   = array[d+1];
                    array[d+1] = swap;
                }
            }
        }
        for(z=0; z<n2; z++)
        {
            if((z+1)%2!=0)
            {
                stones+=array[z];
            }
        }
        printf("%d\n",stones);
        stones = 0;
        z = 0;
    }
    return 0;
}
