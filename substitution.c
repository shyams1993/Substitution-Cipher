#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

/* The Function is declared initially to ensure there's an explicit declaration */
void cipherText(string key, string plaintext);

int main(int argc, string argv[])
{
    /* Exception Check #1 - To check if exactly 2 arguments have been supplied in the command line */
    /* If yes, then the loop further widens and the length of the key argument is checked next */
    if (argc == 2)
    {
        int length = strlen(argv[1]);
        if (length == 26)
        {
            /* Exception Check #2 - To check if the length of the string is exactly 26 */
            /* If and only if the length of the key is 26, the program begins checking if the string has duplicate characters or numbers in it */
            string key = argv[1];
            int counter1 = 0, counter2 = 0;
            bool seen[150] = {false};
            for (int i = 0; i < length; i++)
            {
                /* Exception Check #3 - To check if the letter is an alphabet and that no alphabet repeats twice */
                /* A for loop to iterate over each character to check if each character in the string is an alphabet; If not, increments a counter variable */
                if (isalpha(key[i]))
                {
                    /* Logic to check for repeating characters by declaring a boolean array initialized to false */
                    /* Through the traversal, key[i] is used to reference the boolean array's index and checks if that index is marked as True
                    If that index has been marked as true, then a counter is incremented. If the index has not been marked as true, then we mark it as true */
                    int c = key[i];
                    if (seen[c] == true)
                    {
                        counter1++;
                    }
                    else
                    {
                        seen[c] = true;
                    }
                }
                else
                {
                    counter2++;
                }
            }
            /* Final Exception Check - To ensure that encryption happens only if the key is a valid key */
            /* If and only if both counters are zero, the encryption begins */
            
            if (counter1 == 0 && counter2 == 0)
            {
                string plaintext = get_string("plaintext: ");
                cipherText(key, plaintext);
                printf("\n");
                return 0;
            }
            else
            {
                printf("Enter valid key since this key either contains duplicates or contain non-alphabetic characters.\n");
                return 1;
            }
        }
        else
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
}

/* Function to encrypt the plaintext using the key and plaintext as arguments */

void cipherText(string key, string plaintext)
{
    int ptlength = strlen(plaintext);
    int holder, cipherc;
    printf("ciphertext: ");
    
    /* In this logic, we iterate over the plaintext using a for-loop, finding its alphabetic code (For example, if its A, its alphabetic code is 1; If D, then the code is 4)
    If the letter is uppercased, it simply subtracts the constant by 65 and for lowercase, subtracts it by 97
    This give us the alphabetic code and thus we refer to the key's respective index and print the same. If the alphabetic code is 0, then we print the key's 0th Character.
    The casing of the plaintext (lower or upper) is preserved along with non-alphabetic characters */
    
    for (int x = 0; x < ptlength; x++)
    {
        if (isupper(plaintext[x]))
        {
            holder = plaintext[x] - 65;
            cipherc = key[holder];
            printf("%c", toupper(cipherc));
        }
        else if (islower(plaintext[x]))
        {
            holder = plaintext[x] - 97;
            cipherc = key[holder];
            printf("%c", tolower(cipherc));
        }
        else
        {
            printf("%c", plaintext[x]);
        }
    }
}
