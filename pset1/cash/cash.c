#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) 
{
    float dollar;
    do
    {
        dollar = get_float("Change owed:");           /* Get user input   */
    }
    while (dollar < 0);                           /* Prompt user for input   */
    
    int cents = round(dollar * 100);                  /* Change dollar to cents */
   
    int coins = 0;                                 /*Number of coins */
   
    while (cents >= 25) 
    {
        cents = cents - 25; 
        coins++;
       
    }
    while (cents >= 10) 
    {
        cents = cents - 10;
        coins++;
       
    }
    while (cents >= 5)
    {
        cents = cents - 5;
        coins++;
       
    }
    while (cents >= 1)
    {
        cents = cents - 1;
        coins++;
        
    }
    printf("%i\n", coins);
    
}