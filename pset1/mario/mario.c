#include <stdio.h>
#include <cs50.h>



int main(void)
{
    int n;
    do 
    {
        n = get_int("Whats is the height?\n");     //Ask user for height
    
    }
    while (n < 1 || n > 8);

    for (int i = 1 ; i <= n ; i++)
    {
    
        for (int h = 1 ; h <= (n - i) ; h++)      //Print right allined
        {   
            printf(" "); 
        }
       
       
        for (int j = 1; j <= i; j++)               /* Prints left alighned # */
        {
            printf("#"); 
       
        }
    
        printf("\n");
    } 

}
    
       
    
    