#include<bits/stdc++.h>
using namespace std;

int Left[100009], Right[100009];

int main()
{
    int s, b, l, r, i;

    while(cin >> s >> b)
    {
        if(!s && !b)
            break;

        for(i = 1; i <= s; i++)
        {
            Left[i] = i-1;
            Right[i] = i+1;
        }

        Left[1] = -1;
        Right[s] = -1;

        while(b--)
        {
            cin >> l >> r;

            if(Left[l] != -1)
                cout << Left[l];
            else
                cout << "*";

            cout << " ";

            if(Right[r] != -1)
                cout << Right[r];
            else
                cout << "*";

            cout << "\n";

            Left[Right[r]] = Left[l];
            Right[Left[l]] = Right[r];
        }

        cout << "-\n";
    }
}

/*
Promi's neverland is at war against the demons. As the general of her army, she has decided to attack the enemy with a linear formation of soldiers.
Each soldier is identified by distinct integers from 1 to N, according to their positions in the line.
Furthermore, each soldier in the attack line, must protect his two neighbors in the line, one to his left and one to his right, except those who are in the leftmost position
and the rightmost position. (Because rightmost soldier doesn't have any right neighbor and the leftmost soldier doesn't have any left neighbor).
Everyone knows that if the left or right neighbor of a soldier is killed, then the next living neighbor to the left or to the right of the soldier, respectively, should
become his neighbor.

The battle has started and the demons are very powerful. They can kill a range of human soldiers in just one blow. To win the war, after every attack Promi must know the newly formed neighbors.


The first input line of each test case contains two integers N and A (1 ≤ A ≤ N ≤ 105), the number of soldiers in the line and the number of attacks.
Leftmost soldier is numbered 1 and the rightmost soldier is numbered N. Each of the next
A input lines describes an attack using two integers L (left) and R (right), meaning that soldiers
from L to R (inclusive) were killed (1 ≤ L ≤ R ≤ N). You may assume that until that moment those soldiers were
alive and were just killed.
The last test case is followed by a line containing two zeros.


For each test case output A + 1 lines. In the i-th output line write the new neighbors formed by removing the soldiers that were just killed in the i-th attack. That is, for the
attack ‘L R’, print the first soldier who is still alive to the left of L, and the first soldier who is still alive to the
right of R. For each side, print the character ‘*’ (asterisk) if there is no surviving soldier in that
side. Print a line containing a single character ‘-’ (hyphen) after each test case.

