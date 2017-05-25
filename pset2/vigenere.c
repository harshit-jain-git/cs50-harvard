#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// declaring functions
int equivalent(char a);
int result(char a, int b);
// taking input from the command line.
int main(int argc, string argv[])
{
    // exiting out with an error if improper input is given 
    if (argc != 2)
    {
        printf("ERROR!!\n");
        exit(1);
    }
    
    for(int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] < 'A' || argv[1][i] > 'z' || (argv[1][i] > 'Z' && argv[1][i] < 'a')) 
        {
            printf("ERROR!!\n");
            exit(1);
        }
    }
    
    // asking for plaintext input
    printf("plaintext: ");
    char p[200];
    scanf("%[^\n]s",p);
    // initializing variables
    int l = strlen(argv[1]), k = strlen(p), ptr = 0;
    char c[k];
    // defining the elements of new array by ciphering elements of the plaintext.
    for(int i = 0; i < k; i++)
    {
        if ((p[i] >= 'A' && p[i] <= 'Z') || (p[i] >= 'a' && p[i] <= 'z'))
        {
            c[i] = result(p[i] , equivalent(argv[1][ptr]));
            ptr++;
            ptr = ptr % l;
        }
        else
        {
            c[i] = p[i];
        }
    }
    // printing out the ciphertext.
    printf("ciphertext: ");
    for(int i = 0; i < k; i++)
        printf("%c",c[i]);
    printf("\n");
}

// defining equivalent function
int equivalent(char a)
{
    a = toupper(a);
    return a % 65;
}

// function for ciphering the text taking input of plaintext character and the key.
int result(char a, int b)
{
    char c;
    if (a >= 'A' && a <= 'Z')
        c = (a - 'A' + b) % 26 + 'A';
    else 
        c = (a - 'a' + b) % 26 + 'a';
    return c;
}