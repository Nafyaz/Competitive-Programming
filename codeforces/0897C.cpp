#include<bits/stdc++.h>
using namespace std;

string s1 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s2 = "What are you doing while sending \"";
string s3 = "\"? Are you busy? Will you send \"";
string s4 = "\"?";
long long k, len1 = s1.size(), len2 = s2.size(), len3 = s3.size(), len4 = s4.size();

char func(int n)
{
    if (n == 0 && k > len1)
    {
        k -= len1;
        return '.';
    }
    else if(n == 0)
        return s1[k-1];


    char x;
    if(k > len2)
    {
        k -= len2;
        x = func(n-1);
        if(x != '.')
            return x;
    }
    else
        return s2[k-1];

    if(k > len3)
    {
        k -= len3;
        x = func(n-1);
        if(x != '.')
            return x;
    }
    else
        return s3[k-1];

    if(k > len4)
        return '.';

    return s4[k-1];
}

int main()
{
    int q, n = 2;
    scanf("%d", &q);

    while(q--)
    {
        scanf("%d %lld", &n, &k);
        printf("%c", func(k));
    }
}
