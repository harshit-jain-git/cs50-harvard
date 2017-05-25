#include<stdio.h>
#include<cs50.h>

int main(void){
    int i = 0, j=0;
    // prompts user for input
    printf("Height: ");
    // takes only integer input
    int height = get_int();
    // checks if the height is positive and no more than 23 otherwise prompts user to input the value again
    while(height<0 || height>23) {
        printf("Height: ");
        height = get_int();
    }
    
    for(i=0,j=0;i<height;i++){
        // in each row's starting give required spaces
        for(j=0;j<height-i-1;j++) printf(" ");
        // then prints the # required no.of times
        for(j=height-i-1;j<height;j++) printf("#");
        printf("  ");
        // again prints # required no.of times
        for(j=height;j<height+i+1;j++) printf("#");
        // moves the cursor to new line for printing the next row
        printf("\n");
    }
    return 0;
}