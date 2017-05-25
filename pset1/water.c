#include<stdio.h>
#include<cs50.h>

int main(void){
    // prompting user to input no. of minutes.
    printf("Minutes: ");
    // taking user input until he gives a valid input
    int min = get_int();
    // print the equivalent no.of bottles
    printf("Bottles: %d\n",12*min);
    return 0;
}