#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    char name[50];
    // getting input
    scanf("%[^\n]s",name);
    // tokenizing the string with space as a breaking point
    char* ptr = strtok(name," ");
    // printing the first character of each word in uppercase
    while(ptr != NULL)
    {
        printf("%c",toupper(*ptr));
        ptr = strtok(NULL," ");
    }
    // entering into a new line.
    printf("\n");
    return 0;
}