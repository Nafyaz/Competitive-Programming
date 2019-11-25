#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b;
    cin >> n;
    cin.ignore();

    string s;

    while(n--)
    {
        a = b = 0;
        getline(cin, s);

        if(s.size() < 5)
        {
            printf("OMG>.< I don't know!\n");
            continue;
        }

        if(s.substr(0, 5) == "miao.")
            a = 1;
        if(s.substr(s.size() - 5, 5) == "lala.")
            b = 1;


        if(a && !b)
            printf("Rainbow's\n");
        else if(!a && b)
            printf("Freda's\n");
        else
            printf("OMG>.< I don't know!\n");
    }

}
