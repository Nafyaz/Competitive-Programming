#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[1000];

    int n,i,p=0;
    cin>>n;
    fflush(stdin);
    gets(a);
    cout << a;
    strcpy(a,strlwr(a));
    sort(a,a+n);


    for(i=0; i<n; i++)
    {
        if(a[i]=='a'+p)
            p=p+1;
    }

    if(p==26)
        cout<<"YES";
    else
        cout<<"NO";
}
