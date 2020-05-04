#include<iostream>
#include<string>
using namespace std;
int main()
{
    int pos1=0,pos2=0;
    char dummy;
    string command = {0};
    int n;

    cin >> n;
    //dummy = getchar();
    cin >> command;

    for (int i = 0; i < n; i++)
    {
        if (command[i] == 'L')
            pos1--;
        else if (command[i] == 'R')
            pos2++;
    }

    cout << pos1 << " " << pos2;

//    if (pos1 == 0 || pos2 == 0)
//    {
//        cout << abs(pos1) + abs(pos2);
//    }
//    else if(pos1 != 0 && pos2 != 0)
//    {
//        cout << abs(pos2 - pos1) + 1;
//    }


    return 0;
}
