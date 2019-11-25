#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int h1, m1, h2, m2;
    scanf("%d:%d", &h1, &m1);
    scanf("%d:%d", &h2, &m2);

    int m = (h2*60 + m2 - h1*60 - m1) / 2;
    int h = (m + h1*60 + m1) / 60;
    m = (m + h1*60 + m1) % 60;

    printf("%02d:%02d", h, m);
}
