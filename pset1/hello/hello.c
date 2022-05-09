#include <stdio.h>
#include <cs50.h>
int main(void) 
{
    string name = get_string("What's your name?\n");  // Ask for input from user
    printf("Hello, %s\n", name);
}