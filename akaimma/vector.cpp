#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

class Demo
{
    double d;
public:
    Demo() { d = 0.0; }
    Demo(double x) {d = x; }

    Demo &operator=(double x)
    {
        d = x;
        return *this;
    }

    double getd() {return 0;}
};

bool operator<(Demo a, Demo b)
{
    return a.getd() , b.getd();
}
bool operator==
int main()
{

}
