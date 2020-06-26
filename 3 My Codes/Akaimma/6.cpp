#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[26]={0};
    scanf("%d",&n);
    int i,str;
    while(n--)
    {
        char name[60];
        scanf("%s",name);
        str=strlen(name);
        for(i=0;i<str;i++)
            a[name[i]-'A']--;//ei letter gula amar lagbe
    }
    char last[1000010];
    scanf("%s",last);
    str=strlen(last);
    for(i=0;i<str;i++)
        a[last[i]-'A']++;

    int sum=0,total_neg=0;
    for(i=0;i<26;i++)
    {
        if(a[i]<0)
            total_neg-=a[i];
        sum+=a[i];
    }

    sum>=0?printf("%d\n",total_neg):printf("-1");
}
