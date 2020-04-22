#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int a;
    for(a = 536870915; a <= 1000000000; a++)
    {
        for(int k=2;; k++)
        {
            cout << a << ": " << k << endl;
            int b = pow(2,k)-1;
            if(a%b == 0)
            {
                cout<< k << " " << b << " " << a/b<<endl;
                break;
            }
        }
    }
}
