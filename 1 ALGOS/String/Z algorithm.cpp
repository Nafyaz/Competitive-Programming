#include<bits/stdc++.h>
using namespace std;

int Z[100005];

void z_function(string s)
{
    int i, l, r, n = s.size();
    Z[0] = 0;
    for(i = 1, l = 0, r = 0; i < n; i++)
    {
        if(i <= r) //This condition is false when i=1
            Z[i] = min(r-i+1, Z[i-l]);
        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            Z[i]++; //if Z[1] has previous value, it will cause problem here

        if(i+Z[i] - 1 > r)
        {
            l = i;
            r = i+Z[i]-1;
        }
    }
}

int main()
{

}
