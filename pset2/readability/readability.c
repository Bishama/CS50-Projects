#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string s = get_string("Text: ");                          // Get user Input                                              
   
    int letters = 0;                                           // Count number of letters
    int words = 1;                                               // Count number of words
    int sentences = 0;                                          // Count sentences
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            letters++;
        }
        if (isspace(s[i]))
        {
            words++;
        }
        if (s[i] == '.' || s[i] == '!'  || s[i] == '?')
        {
            sentences++;
        }   
     
    }
   
   
   
    float L = letters / (words / 100.0) ;                       // Applying formula and defining variables
    float S = sentences / (words / 100.0);
    int I = round((0.0588 *  L) - (0.296 * S) - 15.8);
   
    if (I < 1)
    {
        printf("Before Grade 1\n");
    }                                                  // Loop for grade level
    if (I > 16)
    {
        printf("Grade 16+\n");
    }
    else if (I >= 1 && I <= 16)
    {
        printf("Grade %i\n", I);                        //Print grades
    }
   
}
 
 

 
