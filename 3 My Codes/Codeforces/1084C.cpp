//tutorial dekhar por ei code lekhsi.
//ei code lekhar por amar upolobdhi:
//principles and techniques in combinatorics boi ta mukhosto korte hobe.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a = 0, ans = 1;
    char c = '0';
    while(c != '\n')
    {
        scanf("%c", &c);
        if(c == 'a')
            a++;
        if(c == 'b')
        {
            ans = (ans * (a+1)) %1000000007;
            a = 0;
        }
    }

    ans = (ans * (a+1)) %1000000007;
    printf("%lld", (ans-1));
}
