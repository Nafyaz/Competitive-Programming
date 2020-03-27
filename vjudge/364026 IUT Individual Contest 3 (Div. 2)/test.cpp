#include <bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i=1; i<=t; i++)
    {
        int n;
        cin >> n;
        int startx[n], endx[n], starty[n], endy[n];


        for (int j=0; j<n; j++)
           cin >>startx[j]>> starty[j]>> endx[j]>> endy[j];



        sort(startx, startx+n);
        sort(endx, endx+n);
        sort(starty, starty+n);
        sort(endy, endy+n);


        int len= endx[0]-startx[n-1];
        int bre= endy[0]-starty[n-1];


        if (len<0 || bre<0){cout <<"0"<<endl;}
        else
        {
            long long  area = len*bre;
            cout <<"Case"<<" " <<i<<":"<<" " << area <<endl;
        }
    }
}
