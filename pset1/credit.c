#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>

int main(void){
    // prompts the user to give input
    printf("Number: ");
    // takes the input as a long long as the number would not fit into any other smaller type like int.
    long long cardnum = get_long_long();
    // initializing variables
    int i = 0, j, k = 0, sum = 0;
    char num[20];
    // storing the digits of the cardnumber into an array
    while(1){
        num[i] = cardnum%10;
        cardnum = cardnum/10;
        i++;
        if(cardnum == 0) break;
    }
    char num1[i];
    // storing the twice of odd positioned values in an array
    for(j=1;j<i;j=j+2){
        num1[k++] = 2*num[j];
    }
    // finding the sum of digits of twice of the odd positioned digits
    for(j=0;j<k;j++){
        sum+=num1[j]%10 + num1[j]/10;
    }
    // updating the sum by adding even positioned values
    for(j=0;j<i;j=j+2){
        sum+=num[j];
    }
    // checking the card for VISA OR MASTERCARD OR AMEX OR INVALID.
    if(sum%10==0 && i==13) printf("VISA\n");
    else if(sum%10==0 && i==16){
        if(num[i-1]==4) printf("VISA\n");
        else printf("MASTERCARD\n");
    }
    else if(sum%10==0) printf("AMEX\n");
    else printf("INVALID\n");
    return 0;
}