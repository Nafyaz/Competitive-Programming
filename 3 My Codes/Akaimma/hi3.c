#include<stdio.h>
#include<string.h>
int main()
{
    char c[] = {'a', 'A', 'b', 'Z', 'j', 'L', '\0'};
    int i;

    puts(c);
    for(i = 0; i < strlen(c); i++)
    {
        if(c[i] >= 'a' && c[i] <= 'z')
            c[i] -= 32;
        else if(c[i] >= 'A' && c[i] <= 'Z')
            c[i] += 32;
    }
    puts(c);
}
