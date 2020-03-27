#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, n;
    cin >> x >> y >> n;
    for(int i = 1; i <= n; i++)
    {
        if(i%x == 0 && i%y == 0)
            cout << "FizzBuzz" << endl;
        else if(i%x == 0)
            cout << "Fizz" << endl;
        else if(i%y == 0)
            cout << "Buzz" << endl;
        else
            cout << i << endl;
    }
}
