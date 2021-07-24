#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        double ab,ac,bc,r;
        cin >> ab >> ac >> bc >> r;
        cout << fixed;
        cout << "Case " << ++caseno << ": " setprecision(7) << sqrt(ab*ab*r/(1+r)) << "\n";
    }
}
