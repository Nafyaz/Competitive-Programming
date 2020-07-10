#include<bits/stdc++.h>
using namespace std;


int decimal(string s,int n)
{
    int i, j, k, power=1, ans=0 ;
    int len = s.size();
    for( i=len-1,j=0; i>=0 ; i--,j++)
    {

        if( s[i] >= '0' && s[i]<='9' )
            k = s[i]-'0';
        else
            k = s[i]-'A'+10;


        ans += k * power;
        power*=n;

    }
    return ans;
}

string decimaltoany(int n,int k)
{
    string ans;
    int i,j,z;
    for(i=0; n>0; i++)
    {
        z = n%k;
        char r;
        if(z>=0 && z<=9)
            r = (char)(z + '0');
        else
            r = (char)(z - 10 + 'A');

        ans.push_back(r);
        n/=k;
    }

    for(i=ans.size()-1; i>=0; i--)
        cout<<ans[i];
    cout<<endl;

}
int main()
{
    int c,f;
    string s;
    cout<<"enter current base: ";
    cin>>c;
    cout<<"enter the base you want: ";
    cin>>f;
    cout<<"enter variable: ";
    cin>>s;

    int m = decimal(s,c);
    decimaltoany(m,f);
}
