/*
Federal University of Alagoas

Lecture: Introduction to Computing - 2015.1
Student: Marina Francino Lessa Neto Limeira

binary-addition
A (very) simple calculator that sums two binary values using only logic operations.

*/

#include <stdio.h>

//function to return the result of logic operation 'and' between two values
int and (int a, int b) {
    return (a && b);
}

//function to return the result of logic operation 'exclusive or' between two values
int xor (int a, int b) {
    return (a ^ b);   
}

//function to return the result of logic operation 'or' between two values
int or (int a, int b) {
    return (a || b);   
}

void main (int count, char **arguments) {
 
    /*  a: the first entry on the circuit
        b: the second entry on the circuit
        carryIn: the bit that has to be sum with the actual values
        carryOut: the bit that has to be sum with the next values
        The carryOut will always be the same as the carryIn of the next operation.
        
        sum: an array to keep the result of the sum of each case */
    int binary1, binary2;
    int a, b, i;
    int carryIn, carryOut, sum[10];
    
    carryIn = 0;                            //initializing the carryIn with 0, since there's no entry in the first operation.
    
    sscanf (arguments[1], "%d", &binary1);  //converting the first binary from char to integer
    sscanf (arguments[2], "%d", &binary2);  //converting the second binary from char to integer
    
    for (i = 0; i <= 3; i++) {
        
        a = (binary1 % 10); //getting the first value to be used as the last number of the int
        b = (binary2 % 10); //getting the second value to be used as the last number of the int
        
        binary1 = binary1 / 10; //removing the last value of the binary
        binary2 = binary2 / 10; //removing the last value of the binary
        
        sum[i] = xor (xor (a, b), carryIn); //to sum a bit result with the excess value of the previously operation
        
        carryOut = or (and (a, b), and (xor (a, b), carryIn)); //to see if there's any excedent value from the sum
        
        carryIn = carryOut; //setting that the result of the actual operation's carryOut is the next operation carryIn
    }
    
    sum[i] = carryOut;   
    
    //printing the results...
    for (i = 4; i >= 0; i--){
        printf("%d", sum[i]);   
    }
    
    printf("\n");
}
