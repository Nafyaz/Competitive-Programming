#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    cin>>a;

    int choto=110;

    for(int i=1; i<a.size()-1; i++)
    {
        int l=i-1;
        int r=i+1;

        int c=0;

        while(1)
        {
            if(a[l]==a[r])
            {
                l--;
                r++;
                continue;
            }
            else
            {
                c++;
            }

            if(l==0 || r==a.size()-1)
            {
                break;
            }
        }

        choto=max(c,choto);
    }

}
