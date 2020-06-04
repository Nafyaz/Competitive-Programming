#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line, word;
    getline(cin, line);
    stringstream ss (line);
    while(ss >> word)
    {
        cout << word << endl;
    }

}
