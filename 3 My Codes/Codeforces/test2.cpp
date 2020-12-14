#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v1{1,2,3,4,5};
    ofstream out( "v1.txt" );
    copy(v1.begin(), v1.end(),ostream_iterator<int>( out, " " ) );
    freopen("v1.txt","w",stdout);
    vector<int>v2{2,4,6,7,8};
    for(auto u : v2)
        cout << u << " ";

}
