#include<bits/stdc++.h>
using namespace std;

map <string,string> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char st1[15],st2[15],str[15];
    string st;

    while(gets(str)&&str[0]!='\0')
    {
        cout << str << " lol\n";
        sscanf(str,"%s%s",st1,st2);
        m[st2]=st1;
    }


    while( cin>>st)
    {
        if(m[st].size())
            cout<<m[st]<<endl;
        else
            cout<<"eh"<<endl;
    }
    return 0;
}
/*
dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay

atcay
ittenkay
oopslay
*/
