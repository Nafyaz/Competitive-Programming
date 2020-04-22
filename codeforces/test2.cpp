#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int a;
        cin>>a;
        for(int k=2;; k++)
        {
            int b = pow(2,k)-1;
            if(a%b == 0)
            {
                cout<<a/b<<endl;
                break;
            }
        }
    }
}
