#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <crypt.h>
#include <time.h>
#define _XOPEN_SOURCE

int main(int argc, char* argv[])
{
    // declaring variables
    char key[5];
    char salt[3] = "50";
    char*hash;
    int i, j, k, l, status = 0 ;
    // rejecting invalid input.
    if (argc == 1)
        exit(1);
    // checking if a single character is password.
    for(i = 65; i <= 90 || i <= 122; i++)
    {
        key[0] = (char) i;
        key[1] = '\0'; 
        hash = crypt(key, salt);
        // checking if the hash matches the hash of the string and if true then returning from the function by changing status value to 1.
        if (strcmp(hash, argv[1]) == 0)
        {
            printf("%s\n",key);
            status = 1;
            return 0;
        }
        // going to small letters by changing i value to ascii code of 'a'.
        if (i == 90)
        {
            i = 96;
            continue;
        }
    }
    // checking if password has earlier been cracked or not.
    if (status != 1)
        // trying all possible combinations of two letters by iterating two nested loops for two characters.
        for(i = 65; i <= 90 || i <= 122; i++)
        {
            for(j = 65; j <= 90 || j <= 122; j++)
            {
                key[0] = (char) i;
                key[1] = (char) j;
                key[2] = '\0';    
                // calculating the hash by using inbuilt crypt function.
                hash = crypt(key, salt);
                // checking if the hash matches password's hash.
                if (strcmp(hash,argv[1]) == 0)
                {
                    printf("%s\n",key);
                    status = 1;
                    return 0;
                }
                // jumping from letter 'Z' to 'a'
                if (j == 90)
                {
                    j = 96;
                    continue;
                }
            }
            // jumping from letter 'Z' to 'a'
            if (i == 90)
            {
                i = 96;
                continue;
            }
        }
        
    // checking if password has earlier been cracked or not.
    if (status != 1)
        // trying all possible combinations of two letters by iterating two nested loops for two characters.
        for(i = 65; i <= 90 || i <= 122; i++)
        {
            for(j = 65; j <= 90 || j <= 122; j++)
            {
                for(k = 65; k <= 90 || k <= 122; k++)
                {
                    key[0] = (char) i;
                    key[1] = (char) j;
                    key[2] = (char) k;
                    key[3] = '\0'; 
                    // calculating the hash by using inbuilt crypt function.
                    hash = crypt(key, salt);
                    // checking if the hash matches password's hash.
                    if (strcmp(hash,argv[1]) == 0)
                    {
                        printf("%s\n",key);
                        status = 1;
                        return 0;
                    }
                    // jumping from letter 'Z' to 'a'
                    if (k == 90)
                    {
                        k = 96;
                        continue;
                    }
                }
                // jumping from letter 'Z' to 'a'
                if (j == 90)
                {
                    j = 96;
                    continue;
                }
            }
            // jumping from letter 'Z' to 'a'
            if (i == 90)
            {
                i = 96;
                continue;
            }
        }
        
    // checking if password has earlier been cracked or not.    
    if (status != 1)
        // trying all possible combinations of two letters by iterating two nested loops for two characters.
        for(i = 65; i <= 90 || i <= 122; i++)
        {
            for(j = 65; j <= 90 || j <= 122; j++)
            {
                for(k = 65; k <= 90 || k <= 122; k++)
                {
                    for(l = 65; l <= 90 || l <= 122; l++)
                    {
                        key[0] = (char) i;
                        key[1] = (char) j;
                        key[2] = (char) k;
                        key[3] = (char) l;
                        key[4] = '\0'; 
                        // calculating the hash by using inbuilt crypt function.
                        hash = crypt(key, salt);
                        // checking if the hash matches password's hash.
                        if (strcmp(hash, argv[1]) == 0)
                        {
                            printf("%s\n",key);
                            status = 1;
                            return 0;
                        }
                        // jumping from letter 'Z' to 'a'
                        if (l == 90)
                        {
                            l = 96;
                            continue;
                        }
                    }
                    // jumping from letter 'Z' to 'a'
                    if (k == 90)
                    {
                        k = 96;
                        continue;
                    }
                }
                // jumping from letter 'Z' to 'a'
                if (j == 90)
                {
                    j = 96;
                    continue;
                }
            }
            // jumping from letter 'Z' to 'a'
            if (i == 90)
            {
                i = 96;
                continue;
            }
        }
}