//antaji dhil martasi. vul hoile amar kono dosh nai
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int i = m/n;
    while(i > 1)
    {
        if(m%i == 0)
            break;
        i--;
    }
    printf("%d", i);
}
