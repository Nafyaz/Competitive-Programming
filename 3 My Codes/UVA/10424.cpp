#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    int x,sa,sb,lena,lenb,i,j;
    while(getline(cin,a)&&getline(cin,b))
    {

        sa=0;
        sb=0;
        lena=a.length();
        lenb=b.length();

        for(i=0;i<lena;i++)
        {
            if(a[i]>='a'&&a[i]<='z')
                sa=sa+a[i]-'a'+1;
            else if(a[i]>='A'&&a[i]<='Z')
                sa=sa+a[i]-'A'+1;
        }

        for(i=0;i<lenb;i++)
        {
            if(b[i]>='a'&&b[i]<='z')
                sb=sb+b[i]-'a'+1;
            else if(b[i]>='A'&&b[i]<='Z')
                sb=sb+b[i]-'A'+1;
        }

        if(sa%9==0)
            sa=9;
        else
            sa=sa%9;
        if(sb%9==0)
            sb=9;
        else
            sb=sb%9;


        printf("%0.2lf %%\n",100*min(double(sa)/sb,double(sb)/sa));
    }
}

