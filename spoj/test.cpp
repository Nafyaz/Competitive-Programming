#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, s2, s3;
    cin >> s;
    int i, p=0, sum=0;
    for (i = 0; i<s.size(); i++)
    {
        if(s[i]=='e')
        {
            break;
        }
        else
        {
            s2+=s[i];
        }
    }
    for(i=i+1; i<s.size(); i++)
    {
        s3+=s[i];
    }
    for(int j=s3.size()-1; j>=0 ; j--)
    {
        sum+=(s3[j]-'0')*pow(10, p) ;
        p++;
    }

    //cout << sum<<endl;
    if (sum>s2.size()-2)
    {
        int h=sum-s2.size()+2;
        while(h--)
        {
            s2+='0';
        }
    }
    int v=1;
    //cout <<s2<<endl;
    while (sum)
    {
        if(s2[v]=='.')
        {
            swap (s2[v+1], s2[v]);
            sum--;
            v++;
        }
    }

    int l= s2.size();
    if(s2[l-1]=='.')
    {
        s2.erase(l-1);
    }

    while(s2[0]==0 && s[1]!='.' )
    {
        s2.erase(0,1);
    }
    int z=0;


    if(int g=2 ; g<s2.size() ; g++)
    {
        if(s2[g]!=0)
        {
            z++;
        }
    }
    if(z==0)
    {
        cout << s[0];
        return 0;
    }
    cout << s2;


}
