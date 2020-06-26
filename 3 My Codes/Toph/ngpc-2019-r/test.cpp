#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0); cin.tie(NULL)
#define PI acos(-1.0)
#define TEST(n) cout<<"dhukse"<<n<<'\n'


/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////Coded By: pranonrahman///////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    long long unsigned t;
    cin >> t;
    while(t--)
    {
        long long unsigned l,r;
        cin >> l >> r;
        long long unsigned a1 = (long long unsigned)ceil(log2(l));
        long long unsigned a2 = (long long unsigned)ceil(log2(r));
        long long unsigned aa1 = (1 << a1)-1  ;
        long long unsigned aa2 = (1 << a2)-1;
       // cout << aa2 << ' ' << aa1 << endl;
        if(l>r)     cout << 0 << '\n';
        else        cout << aa2-aa1 << '\n';
    }

    return 0;
}
