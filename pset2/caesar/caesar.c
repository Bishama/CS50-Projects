#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    
    if (argc != 2)                                                // Check for 2 command line arguments. 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
     
    for (int i = 0, n = strlen(argv[1]) ; i < n; i++)                         // Check each character in the string argv to be a digit
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    int key = atoi(argv[1]);                                            // Change string to int
    string plainText = get_string("plaintext:");                     // Get plain text from user
    
    printf("ciphertext:");
    for (int j = 0, n = strlen(plainText); j < n; j++)             // ACCESS each character in plain text
    {
      
        if (isupper(plainText[j])
            && isalpha(plainText[j]))                                      //check if each character in plaintext is uppercase letter
        {
            plainText[j] -=
                65;                                                                        // convert plaintext characters to alphabetic index numbers
            plainText[j] = (plainText[j] + key) % 
                           26;                                                                   //cipher = (plain + key) % 26
            plainText[j] +=
                65;                                                                               // convert number back to ASCII number
        }                                                                             
      
                                                                                 
        if (islower(plainText[j]) && isalpha(plainText[j]))
        {
            plainText[j] -= 97;
            plainText[j] = (plainText[j] + key) % 26;
            plainText[j] += 97;
        }
      
      
        if (isblank(plainText[j]) || isdigit(plainText[j]) || ispunct(plainText[j]))
        {
            plainText[j] = plainText[j];
        } 
        printf("%c", plainText[j]);
     
    }
    
    printf("\n");   
}
     
    